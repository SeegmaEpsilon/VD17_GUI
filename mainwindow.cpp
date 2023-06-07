#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cbA(32),
    cbV(32),
    counter(0),
    valueA(0),
    valueV(0),
    flagMeasureDone(0),
    buttonState(0),
    isMouseHold_(false)
{
    ui->setupUi(this);

    QString aboutSoftware = "Микроникс, Омск 2023. Версия 2.0";
    ui->label_aboutSoftware->setText(aboutSoftware);

    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    ui->canvas->setInteraction(QCP::iRangeDrag, true);
    ui->canvas->setInteraction(QCP::iRangeZoom, true);
    ui->canvas->xAxis->setLabel("Точки отсчета");
    ui->canvas->yAxis->setLabel("A, V");

    serialPortCheckout();

    connect(&serialTimer, SIGNAL(timeout()), this, SLOT(serialPortCheckout()));
    serialTimer.start(MS_SERIAL_TIMEOUT);

    disable_all_widgets();

    /* Коннекты связей между плоттером графиков и GUI */
    connect(ui->canvas, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(slotMouseMove(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(slotMouseDoubleClick(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(slotMousePress(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(slotMouseRelease(QMouseEvent*)));
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
    if(buttonState == COM_PORT_DISCONNECTED)
    {
        QString numStr;
        foreach(numStr, ui->comboBox_port->currentText().split(" ", QString::SkipEmptyParts))
        {
            if(numStr.contains("COM")) break;
            else continue;
        }

        serialPort.setPortName(numStr);

        if (!serialPort.open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
            return;
        }
        else
        {
            ui->pushButton_COM_connect->setText(QString::fromUtf8("Отключиться"));

            connect(&serialPort, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
            buttonState = COM_PORT_CONNECTED;
        }
    }
    else if(buttonState == COM_PORT_CONNECTED)
    {
      ui->pushButton_COM_connect->setText(QString::fromUtf8("Подключиться"));

      disable_all_widgets();
      buttonState = COM_PORT_DISCONNECTED;

      if(serialPort.isOpen())
      {
        serialPort.close();
      }
    }
}

void MainWindow::receiveMessage()
{
    QString code = "***";

    QByteArray dataBA = serialPort.readAll();
    QString data(dataBA);

    serialBuffer.append(data);

    int index = serialBuffer.indexOf(code);

    if(index != -1)
    {
        QString message = serialBuffer.mid(0, index);
        if(message.contains("[DEBUG]", Qt::CaseInsensitive))
        {
          plotGraph(message);
        }
        else if(message.contains("[INIT]", Qt::CaseInsensitive))
        {
            printConsole(message);
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
        serialBuffer.remove(0, index + code.size());
    }
}
