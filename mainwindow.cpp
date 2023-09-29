#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cbA(32),            // Кольцевой буфер на 32 элемента
    cbV(32),            // Кольцевой буфер на 32 элемента
    counter(0),         // Счетчик принятых значений
    valueA(0),          // Текущее значение виброускорения
    valueV(0),          // Текущее значение виброскорости
    flagMeasureDone(0), // Флаг, показывающий, что текущее измерение закончено
    buttonState(0),     // Состояние кнопки подключиться/отключиться
    isMouseHold_(false) // Отслеживает, зажата ли ЛКМ или нет (для графика)

{
    ui->setupUi(this);

    /* Коннекты связей между плоттером графиков и GUI */
    connect(ui->canvas, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(slotMouseMove(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(slotMouseDoubleClick(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(slotMousePress(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(slotMouseRelease(QMouseEvent*)));

    connect(&settingsUI_, SIGNAL(needSaveSettings(appSettingsStruct)), this, SLOT(saveAppSettings(appSettingsStruct)));
    connect(this, SIGNAL(setSettingsUI(appSettingsStruct)), &settingsUI_, SLOT(setVisibleSettings(appSettingsStruct)));

    connect(&serialTimer, SIGNAL(timeout()), this, SLOT(serialPortCheckout()));

    initializeAppSettings();

    /* Настройка холста, на котором будет отрисовываться график
       Разрешаем зум и перемещение по графику */
    ui->canvas->setInteraction(QCP::iRangeDrag, true);
    ui->canvas->setInteraction(QCP::iRangeZoom, true);
    ui->canvas->xAxis->setLabel("Точки отсчета");
    ui->canvas->yAxis->setLabel("A, V");

    /* Первое сканирование на наличие COM-портов */
    serialPortCheckout();

    /* Инициализация таймера, по которому будут сканироваться COM-порты */

    serialTimer.start(MS_SERIAL_TIMEOUT);
    disable_all_widgets();
}

MainWindow::~MainWindow()
{
  if(serialPort->isOpen())
  {
    serialPort->close();
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
            qDebug() << "Ошибка установки скорости передачи: " << serialPort->errorString();
            serialPort->close();
            delete serialPort;
            serialPort = NULL; // Use NULL here
            return;
        }

        // Successfully connected
        qDebug() << "baudRate:" << serialPort->baudRate();
        qDebug() << "parity:" << serialPort->parity();
        qDebug() << "stopBits:" << serialPort->stopBits();
        qDebug() << "dataBits:" << serialPort->dataBits();
        qDebug() << "flowControl:" << serialPort->flowControl();

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



/* Функция обработчик сообщений через UART */
void MainWindow::receiveMessage()
{
    QByteArray dataBA = serialPort->readAll(); // Получаем массив байтов с данными
    QString data(dataBA); // Преобразуем байты в строку

    qDebug() << data;

    serialBuffer.append(data); // Добавляем в буфер данные

    int index = serialBuffer.indexOf(messageCode_); // Ищем индекс кодовой последовательности в строке

    /* Если нашли, то обрабатываем */
    if(index != -1)
    {
        QString message = serialBuffer.mid(0, index); // Получаем строку от 0 до искомого кода
        if(message.contains("[DEBUG]", Qt::CaseInsensitive))
        {
          plotGraph(message); // Если в сообщении есть отладка, то строим график по входящим данным
        }
        else if(message.contains("[INIT]", Qt::CaseInsensitive))
        {
            printConsole(message); // Выводим сообщения об инициализации
            if(message.contains("Waiting for a command", Qt::CaseInsensitive))
            {
              reset_all_widgets();
            }
            else if(message.contains("Micronix", Qt::CaseInsensitive))
            {
              disable_all_widgets();
            }
            else if(message.contains("Correction ratio of 4mA", Qt::CaseInsensitive))
            {
                foreach(QString numStr, message.split(" ", QString::SkipEmptyParts))
                {
                    bool check = false;
                    numStr.toInt(&check);
                    if(check)
                    {
                        ui->lineEdit_DL_value->setValue(numStr.toInt());
                    }
                }
            }
            else if(message.contains("Correction ratio of 20mA", Qt::CaseInsensitive))
            {
                foreach(QString numStr, message.split(" ", QString::SkipEmptyParts))
                {
                    bool check = false;
                    numStr.toInt(&check);
                    if(check)
                    {
                        ui->lineEdit_UL_value->setValue(numStr.toInt());
                    }
                }
            }
            else if(message.contains("Max mm per sec", Qt::CaseInsensitive))
            {
                foreach(QString numStr, message.split(" ", QString::SkipEmptyParts))
                {
                    int index = ui->cmb_mmpersec->findText(numStr, Qt::MatchContains);
                    if(index != -1) ui->cmb_mmpersec->setCurrentIndex(index);
                }
            }
            else if(message.contains("Dynamic range", Qt::CaseInsensitive))
            {
                foreach(QString numStr, message.split(" ", QString::SkipEmptyParts))
                {
                    int index = ui->cmb_dynamic_ranges->findText(numStr);
                    if(index != -1) ui->cmb_dynamic_ranges->setCurrentIndex(index);
                }
            }
        }
        else printConsole(message);
        serialBuffer.remove(0, index + messageCode_.size()); // Удаляем обработанное сообщение из очереди
    }
}

void MainWindow::on_pushButton_settings_clicked()
{
    settingsUI_.show();
}
