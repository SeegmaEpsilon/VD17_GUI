#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cbA(32),            // Кольцевой буфер на 32 элемента
    cbV(32),            // Кольцевой буфер на 32 элемента
    cbT(32),            // Кольцевой буфер на 32 элемента
    valueA(0),          // Текущее значение виброускорения
    valueV(0),          // Текущее значение виброскорости
    counterA(0),        // Счетчик на графике для ускорения
    counterV(0),        // Счетчик на графике для скорости
    flagMeasureDone(0), // Флаг, показывающий, что текущее измерение закончено
    buttonState(0),     // Состояние кнопки подключиться/отключиться
    isMouseHold_(false) // Отслеживает, зажата ли ЛКМ или нет (для графика)

{
    ui->setupUi(this);

    ui->cmb_dynamic_ranges->setEditable(true);
    ui->cmb_dynamic_ranges->lineEdit()->setReadOnly(true);
    ui->cmb_dynamic_ranges->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->cmb_axis->setEditable(true);
    ui->cmb_axis->lineEdit()->setReadOnly(true);
    ui->cmb_axis->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->cmb_axis_measuring->setEditable(true);
    ui->cmb_axis_measuring->lineEdit()->setReadOnly(true);
    ui->cmb_axis_measuring->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->cmb_constant_component->setEditable(true);
    ui->cmb_constant_component->lineEdit()->setReadOnly(true);
    ui->cmb_constant_component->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->cmb_measuring_parameter->setEditable(true);
    ui->cmb_measuring_parameter->lineEdit()->setReadOnly(true);
    ui->cmb_measuring_parameter->lineEdit()->setAlignment(Qt::AlignCenter);

    on_cmb_graph_selector_currentIndexChanged(ui->cmb_graph_selector->currentIndex());

    initializeConnects();
    initializeAppSettings();
    initializeMenu();

    /* Инициализация таймера, по которому будут сканироваться COM-порты */
    /* Первое сканирование на наличие COM-портов */
    serialPortCheckout();
    serialTimer.start(MS_SERIAL_TIMEOUT);
}

MainWindow::~MainWindow()
{
    // Disconnect and clean up resources
    if(serialPort)
    {
        serialPort->close();
        delete serialPort;
        serialPort = nullptr; // Use NULL here
    }
    delete ui;
}

void MainWindow::on_pushButton_COM_connect_clicked()
{
    if (buttonState == COM_PORT_DISCONNECTED)
    {
        QString comPortName;

        // Extract the COM port name from the combo box
        foreach (const QString &str, ui->comboBox_port->currentText().split(" ", QString::SkipEmptyParts))
        {
            if (str.contains("COM"))
            {
                comPortName = str;
                break;
            }
        }

        if (comPortName.isEmpty())
        {
            QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Недопустимое имя порта"));
            return;
        }

        // Initialize the serial port
        serialPort = new QSerialPort(comPortName);

        if (!serialPort->open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
            delete serialPort;
            serialPort = NULL; // Use NULL here
            return;
        }

        // Configure the serial port
        serialPort->setBaudRate(baudRate_);
        serialPort->setDataBits(dataBits_);
        serialPort->setParity(parityControl_);
        serialPort->setStopBits(stopBits_);
        serialPort->setFlowControl(flowControl_);

        if (serialPort->error() != QSerialPort::NoError)
        {
            QString message = "Ошибка установки скорости передачи: " + serialPort->errorString();
            printConsole(message);
            serialPort->close();
            delete serialPort;
            serialPort = NULL; // Use NULL here
            return;
        }

        connect(serialPort, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
        buttonState = COM_PORT_CONNECTED;
        ui->pushButton_COM_connect->setText(QString::fromUtf8("Отключиться"));
        ui->pushButton_userCommand->setEnabled(true);
    }
    else if (buttonState == COM_PORT_CONNECTED)
    {
        // Disconnect and clean up resources
        if (serialPort)
        {
            serialPort->close();
            delete serialPort;
            serialPort = NULL; // Use NULL here
        }

        buttonState = COM_PORT_DISCONNECTED;
        ui->pushButton_COM_connect->setText(QString::fromUtf8("Подключиться"));
        ui->pushButton_userCommand->setEnabled(false);
    }
}

void MainWindow::receiveMessage()
{
    QByteArray data = serialPort->readAll();
    serialBuffer.append(data);

    // Обработка полных сообщений в буфере
    while (!serialBuffer.isEmpty())
    {
        int endIndex = serialBuffer.indexOf(messageCode_); // Предположим, что сообщения заканчиваются символом новой строки
        if (endIndex == -1) break; // Если нет полного сообщения, выходим из цикла

        QString message = serialBuffer.left(endIndex); // Извлекаем сообщение
        serialBuffer.remove(0, endIndex + 1); // Удаляем обработанное сообщение из буфера

        processMessage(message); // Обработка извлеченного сообщения
    }
}

void MainWindow::processMessage(const QString &message)
{
    // Маппинг ключевых фраз на методы и соответствующие элементы UI для сообщений отладки
    const std::map<QString, std::function<void()>> debugActions =
    {
        {"x_mg", [this, &message](){ updateLineEditValue(ui->lineEdit_x_mg, message); }},
        {"y_mg", [this, &message](){ updateLineEditValue(ui->lineEdit_y_mg, message); }},
        {"z_mg", [this, &message](){ updateLineEditValue(ui->lineEdit_z_mg, message); }},
        {"A_x", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_A_x, 0, 0); }},
        {"A_y", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_A_y, 0, 1); }},
        {"A_z", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_A_z, 0, 2); }},
        {"A_m", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_A_xyz, 0, 3); }},
        {"V_x", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_V_x, 1, 0); }},
        {"V_y", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_V_y, 1, 1); }},
        {"V_z", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_V_z, 1, 2); }},
        {"V_m", [this, &message](){ handleAxis(message, ui->lineEdit_RMS_V_xyz, 1, 3); }},
        {"current_buffer", [this, &message](){ updateLineEditValue(ui->lineEdit_current_buffer, message); }},
        {"current_samples", [this, &message](){ updateLineEditValue(ui->lineEdit_samples_reserve, message); }},
        {"T_rms", [this, &message](){ updateLineEditValue(ui->lineEdit_RMS_T, message); }},
        {"PWM_value", [this, &message](){ updateLineEditValue(ui->lineEdit_PWM_value, message); }}
    };

    if (message.contains("[DEBUG]", Qt::CaseInsensitive))
    {
        for (const auto& action : debugActions) {
            if (message.contains(action.first, Qt::CaseInsensitive))
            {
                action.second();
                return;
            }
        }
    }
    else if (message.contains("[INIT]", Qt::CaseInsensitive))
    {
        handleInitMessage(message);
    } else {
        printConsole(message);
    }
}

void MainWindow::handleAxis(const QString &message, QLineEdit *lineEdit, int graphRow, int graphColumn)
{
    updateLineEditValue(lineEdit, message);
    plotGraph(graphRow, graphColumn, lineEdit->text().toFloat());
}

void MainWindow::handleInitMessage(const QString &message)
{
    // Маппинг ключевых фраз на методы и соответствующие элементы UI
    const std::map<QString, std::function<void(const QString&)>> actionMap =
    {
        {"Sensor started", [this](const QString& msg) { printConsole(msg); }},
        {"Restarting MCU", [this](const QString& msg) { printConsole(msg); }},
        {"Code 4mA", [this](const QString& msg) { updateSpinBoxValue(ui->lineEdit_DL_value, msg); }},
        {"Code 20mA", [this](const QString& msg) { updateSpinBoxValue(ui->lineEdit_UL_value, msg); }},
        {"Max parameter value", [this](const QString& msg) { updateLineEditValue(ui->lineEdit_mmpersec_value, msg); }},
        {"Dynamic range", [this](const QString& msg) { updateComboBoxValue(ui->cmb_dynamic_ranges, msg); }},
        {"Measuring axis", [this](const QString& msg) { updateComboBoxValue(ui->cmb_axis_measuring, msg); }},
        {"Last calibrated axis", [this](const QString& msg) { updateComboBoxValue(ui->cmb_axis, msg); }},
        {"Measuring parameter", [this](const QString& msg) { updateComboBoxValue(ui->cmb_measuring_parameter, msg); }},
        {"Thermo slope", [this](const QString& msg) { updateLineEditValue(ui->lineEdit_thermoslope, msg); }},
        {"Thermo intercept", [this](const QString& msg) { updateLineEditValue(ui->lineEdit_thermointercept, msg); }},
        {"Thermo low", [this](const QString& msg) { updateLineEditValue(ui->lineEdit_thermo_lowTemperature_constant, msg); }},
        {"Constant velocity", [this](const QString& msg) { updateLineEditValue(ui->lineEdit_constant_value, msg); }},
        {"Constant component", [this](const QString& msg) { updateComboBoxValue(ui->cmb_constant_component, msg); }}
    };

    for (auto it = actionMap.begin(); it != actionMap.end(); ++it)
    {
        if (message.contains(it->first, Qt::CaseInsensitive))
        {
            it->second(message);
            return;
        }
    }

    printConsole(message);
}

void MainWindow::updateLineEditValue(QLineEdit *lineEdit, const QString &message)
{
    foreach (QString numStr, message.split(" ", QString::SkipEmptyParts))
    {
        bool check = false;
        numStr.toFloat(&check);
        if (check)
        {
            lineEdit->setText(numStr);
            break;
        }
    }
}

void MainWindow::updateComboBoxValue(QComboBox *comboBox, const QString &message)
{
    foreach (QString numStr, message.split(" ", QString::SkipEmptyParts))
    {
        bool check = false;
        int index = numStr.toInt(&check);
        if (check)
        {
            comboBox->setCurrentIndex(index);
            break;
        }
    }
}

void MainWindow::updateSpinBoxValue(QSpinBox *spinBox, const QString &message)
{
    foreach (QString numStr, message.split(" ", QString::SkipEmptyParts))
    {
        bool check = false;
        int value = numStr.toInt(&check);
        if (check)
        {
            spinBox->setValue(value);
            break;
        }
    }
}


void MainWindow::on_pushButton_settings_clicked()
{
    settingsUI_.show();
}

void MainWindow::on_cmb_graph_selector_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->canvas_A->setVisible(true);
        ui->canvas_V->setVisible(false);
    }
    else if(index == 1)
    {
        ui->canvas_A->setVisible(false);
        ui->canvas_V->setVisible(true);
    }
    else if(index == 2)
    {
        ui->canvas_A->setVisible(true);
        ui->canvas_V->setVisible(true);
    }
}
