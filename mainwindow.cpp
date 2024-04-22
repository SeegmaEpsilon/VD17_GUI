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

    initializeConnects();
    initializeAppSettings();
    initializeMenu();

    /* Инициализация таймера, по которому будут сканироваться COM-порты */
    /* Первое сканирование на наличие COM-портов */
    serialPortCheckout();
    serialTimer.start(MS_SERIAL_TIMEOUT);

    disable_all_widgets();
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
        disable_all_widgets();
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
        int endIndex = serialBuffer.indexOf('\n'); // Предположим, что сообщения заканчиваются символом новой строки
        if (endIndex == -1) break; // Если нет полного сообщения, выходим из цикла

        QString message = serialBuffer.left(endIndex); // Извлекаем сообщение
        serialBuffer.remove(0, endIndex + 1); // Удаляем обработанное сообщение из буфера

        processMessage(message); // Обработка извлеченного сообщения
    }
}

void MainWindow::processMessage(const QString & message)
{
    if (message.contains("[DEBUG]", Qt::CaseInsensitive))
    {
        if (message.contains("x_mg", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_x_mg, message);
        }
        else if (message.contains("y_mg", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_y_mg, message);
        }
        else if (message.contains("z_mg", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_z_mg, message);
        }
        else if (message.contains("A_x", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_A_x, message);
            plotGraph(0, 0, ui->lineEdit_RMS_A_x->text().toFloat());
        }
        else if (message.contains("A_y", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_A_y, message);
            plotGraph(0, 1, ui->lineEdit_RMS_A_y->text().toFloat());
        }
        else if (message.contains("A_z", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_A_z, message);
            plotGraph(0, 2, ui->lineEdit_RMS_A_z->text().toFloat());
        }
        else if (message.contains("A_m", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_A_xyz, message);
            plotGraph(0, 3, ui->lineEdit_RMS_A_xyz->text().toFloat());
        }
        else if (message.contains("V_x", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_V_x, message);
            plotGraph(1, 0, ui->lineEdit_RMS_V_x->text().toFloat());
        }
        else if (message.contains("V_y", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_V_y, message);
            plotGraph(1, 1, ui->lineEdit_RMS_V_y->text().toFloat());
        }
        else if (message.contains("V_z", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_V_z, message);
            plotGraph(1, 2, ui->lineEdit_RMS_V_z->text().toFloat());
        }
        else if (message.contains("V_m", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_V_xyz, message);
            plotGraph(1, 3, ui->lineEdit_RMS_V_xyz->text().toFloat());
        }
        else if (message.contains("current_buffer", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_current_buffer, message);
        }
        else if (message.contains("current_samples", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_samples_reserve, message);
        }
        else if (message.contains("T_rms", Qt::CaseInsensitive))
        {
            updateLineEditValue(ui->lineEdit_RMS_T, message);
        }
    }
    else if (message.contains("[INIT]", Qt::CaseInsensitive))
    {
        handleInitMessage(message);
    }
    else
    {
        printConsole(message);
    }
}

void MainWindow::handleInitMessage(const QString &message)
{
    if (message.contains("Waiting for a command", Qt::CaseInsensitive))
    {
        printConsole(message);
        reset_all_widgets();
    }
    else if (message.contains("Sensor started", Qt::CaseInsensitive) || message.contains("Restarting MCU", Qt::CaseInsensitive))
    {
        printConsole(message);
        disable_all_widgets();
    }
    else if (message.contains("Code 4mA", Qt::CaseInsensitive))
    {
        updateSpinBoxValue(ui->lineEdit_DL_value, message);
    }
    else if (message.contains("Code 20mA", Qt::CaseInsensitive))
    {
        updateSpinBoxValue(ui->lineEdit_UL_value, message);
    }
    else if (message.contains("Max velocity", Qt::CaseInsensitive))
    {
        updateLineEditValue(ui->lineEdit_mmpersec_value, message);
    }
    else if (message.contains("Dynamic range", Qt::CaseInsensitive))
    {
        updateComboBoxValue(ui->cmb_dynamic_ranges, message);
    }
    else if (message.contains("Measuring axis", Qt::CaseInsensitive))
    {
        updateComboBoxValue(ui->cmb_axis_measuring, message);
        updateComboBoxValue(ui->cmb_axis, message);
    }
    else if (message.contains("Thermo slope", Qt::CaseInsensitive))
    {
        updateLineEditValue(ui->lineEdit_thermoslope, message);
    }
    else if (message.contains("Thermo intercept", Qt::CaseInsensitive))
    {
        updateLineEditValue(ui->lineEdit_thermointercept, message);
    }
    else if (message.contains("Thermo low", Qt::CaseInsensitive))
    {
        updateLineEditValue(ui->lineEdit_thermo_lowTemperature_constant, message);
    }
    else if (message.contains("Constant velocity", Qt::CaseInsensitive))
    {
        updateLineEditValue(ui->lineEdit_constant_value, message);
    }
    else if (message.contains("Constant component", Qt::CaseInsensitive))
    {
        updateComboBoxValue(ui->cmb_constant_component, message);
    }
    else
    {
        printConsole(message);
    }
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
