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
    connect(&serialTimer, SIGNAL(timeout()), this, SLOT(serialPortCheckout()));
    serialTimer.start(MS_SERIAL_TIMEOUT);

    disable_all_widgets();
}

MainWindow::~MainWindow()
{
  if(serialPort.isOpen())
  {
    serialPort.close();
  }
    delete ui;
}

void MainWindow::on_pushButton_COM_connect_clicked()
{
    /* В случае, если подключения не было, то находит в текущем значении комбобокса имя COM-порта */
    if(buttonState == COM_PORT_DISCONNECTED)
    {
        QString numStr;
        foreach(numStr, ui->comboBox_port->currentText().split(" ", QString::SkipEmptyParts))
        {
            if(numStr.contains("COM")) break;
            else continue;
        }

        /* Задаем имя последовательному интерфейсу */
        serialPort.setPortName(numStr);

        if (!serialPort.open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
            return;
        }
        else
        {
            ui->pushButton_COM_connect->setText(QString::fromUtf8("Отключиться"));

            /* Если подключение осуществлено, то сигнал готовности о чтении связываем с функцием-обработчиком */
            connect(&serialPort, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
            buttonState = COM_PORT_CONNECTED;
            ui->pushButton_userCommand->setEnabled(true);
        }
    }
    else if(buttonState == COM_PORT_CONNECTED)
    {
      ui->pushButton_COM_connect->setText(QString::fromUtf8("Подключиться"));

      disable_all_widgets();
      buttonState = COM_PORT_DISCONNECTED;
      ui->pushButton_userCommand->setEnabled(false);

      if(serialPort.isOpen())
      {
        serialPort.close();
      }
    }
}

/* Функция обработчик сообщений через UART */
void MainWindow::receiveMessage()
{

    QByteArray dataBA = serialPort.readAll(); // Получаем массив байтов с данными
    QString data(dataBA); // Преобразуем байты в строку

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
        serialBuffer.remove(0, index + messageCode_.size()); // Удаляем обработанное сообщение из очереди
    }
}

void MainWindow::on_pushButton_settings_clicked()
{
    settingsUI_.show();
}
