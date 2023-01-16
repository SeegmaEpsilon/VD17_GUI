#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>

#define CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION "DLSS"
#define CMD_DOWN_LIMIT_CURRENT_LOOP_WRITE "DLW"

#define CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION "ULSS"
#define CMD_UP_LIMIT_CURRENT_LOOP_WRITE "ULWW"

#define CMD_MM_PER_SEC_SET "MMSS"
#define CMD_MM_PER_SEC_WRITE "MMW"

#define CMD_DYNAMIC_MODE_SET "MDRS"
#define CMD_DYNAMIC_MODE_WRITE "MW"

#define CMD_FLASH_WRITE "WSTF"
#define CMD_CALIBRATE_DEVICE "CLBR"
#define CMD_MCU_RESTART "REST"


enum BUTTON_STATE
{
    COM_PORT_DISCONNECTED = 0,
    COM_PORT_CONNECTED = 1
};

int buttonState = 0;

void MainWindow::disable_all_widgets()
{
    ui->pushButton_DL_calibration->setEnabled(false);
    ui->pushButton_DL_multimeter->setEnabled(false);
    ui->pushButton_DL_write->setEnabled(false);
    ui->pushButton_UL_calibration->setEnabled(false);
    ui->pushButton_UL_multimeter->setEnabled(false);
    ui->pushButton_UL_write->setEnabled(false);
    ui->pushButton_dynamic_range_set->setEnabled(false);
    ui->pushButton_dynamic_range_write->setEnabled(false);
    ui->pushButton_mmpersec_calibration->setEnabled(false);
    ui->pushButton_mmpersec_write->setEnabled(false);
    ui->pushButton_calibrate_device->setEnabled(false);
    ui->lineEdit_DL_value->setEnabled(false);
    ui->lineEdit_UL_value->setEnabled(false);
    ui->cmb_mmpersec->setEnabled(false);
    ui->cmb_dynamic_ranges->setEnabled(false);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(QString("%1 (%2)").arg(serialPortInfo.portName(), serialPortInfo.description()));
    }

    this->setWindowTitle(QString::fromUtf8("ВД17 - Настройки"));

    ui->lineEdit_DL_value->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
    ui->lineEdit_UL_value->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));

    counter = 0;
    ui->canvas->addGraph();
    ui->canvas->setInteraction(QCP::iRangeDrag, true);
    ui->canvas->setInteraction(QCP::iRangeZoom, true);
    ui->canvas->xAxis->setLabel("t");
    ui->canvas->yAxis->setLabel("V");
}

MainWindow::~MainWindow()
{
    serialPort.close();
    delete ui;
}

void MainWindow::on_pushButton_DL_calibration_clicked()
{
    disable_all_widgets();
    ui->lineEdit_DL_value->setEnabled(true);
    ui->pushButton_DL_multimeter->setEnabled(true);
    ui->pushButton_DL_write->setEnabled(true);

    serialPort.write(CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION);
}

void MainWindow::on_pushButton_DL_multimeter_clicked()
{
    if  (ui->lineEdit_DL_value->text().size() == 0)
    {
            QString str_temp = "113";
            ui->lineEdit_DL_value->setText(str_temp);
    }
    else if(ui->lineEdit_DL_value->text().size() == 1)
    {
        QString str_temp = ui->lineEdit_DL_value->text();
        str_temp = "00" + str_temp;
        ui->lineEdit_DL_value->setText(str_temp);
    }
    else if(ui->lineEdit_DL_value->text().size() == 2)
    {
        QString str_temp = ui->lineEdit_DL_value->text();
        str_temp = "0" + str_temp;
        ui->lineEdit_DL_value->setText(str_temp);
    }

    const char* pcData = ui->lineEdit_DL_value->text().toStdString().c_str();
    serialPort.write(pcData);
}

void MainWindow::on_pushButton_DL_write_clicked()
{
    serialPort.write(CMD_DOWN_LIMIT_CURRENT_LOOP_WRITE);

    disable_all_widgets();
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_dynamic_range_set->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_calibrate_device->setEnabled(true);
}

void MainWindow::on_pushButton_UL_calibration_clicked()
{
    disable_all_widgets();
    ui->lineEdit_UL_value->setEnabled(true);
    ui->pushButton_UL_multimeter->setEnabled(true);
    ui->pushButton_UL_write->setEnabled(true);

    serialPort.write(CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION);
}

void MainWindow::on_pushButton_UL_multimeter_clicked()
{
    if(ui->lineEdit_UL_value->text().size() == 0)
    {
        QString str_temp = "1576";
        ui->lineEdit_UL_value->setText(str_temp);
    }
    if(ui->lineEdit_UL_value->text().size() == 1)
    {
        QString str_temp = ui->lineEdit_UL_value->text();
        str_temp = "000" + str_temp;
        ui->lineEdit_UL_value->setText(str_temp);
    }
    if(ui->lineEdit_UL_value->text().size() == 2)
    {
        QString str_temp = ui->lineEdit_UL_value->text();
        str_temp = "00" + str_temp;
        ui->lineEdit_UL_value->setText(str_temp);
    }
    if(ui->lineEdit_UL_value->text().size() == 3)
    {
        QString str_temp = ui->lineEdit_UL_value->text();
        str_temp = "0" + str_temp;
        ui->lineEdit_UL_value->setText(str_temp);
    }

    const char* pcData = ui->lineEdit_UL_value->text().toStdString().c_str();
    serialPort.write(pcData);
}

void MainWindow::on_pushButton_UL_write_clicked()
{
    serialPort.write(CMD_UP_LIMIT_CURRENT_LOOP_WRITE);
    disable_all_widgets();
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_dynamic_range_set->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_calibrate_device->setEnabled(true);
}

void MainWindow::on_pushButton_mmpersec_calibration_clicked()
{
    disable_all_widgets();
    ui->cmb_mmpersec->setEnabled(true);
    ui->pushButton_mmpersec_write->setEnabled(true);

    serialPort.write(CMD_MM_PER_SEC_SET);
}

void MainWindow::on_pushButton_mmpersec_write_clicked()
{
    const char* pcData = ui->cmb_mmpersec->currentText().toStdString().c_str();
    serialPort.write(pcData);

    disable_all_widgets();
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_dynamic_range_set->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_calibrate_device->setEnabled(true);
}


void MainWindow::on_pushButton_dynamic_range_set_clicked()
{
    disable_all_widgets();
    ui->cmb_dynamic_ranges->setEnabled(true);
    ui->pushButton_dynamic_range_write->setEnabled(true);

    serialPort.write(CMD_DYNAMIC_MODE_SET);
}

void MainWindow::on_pushButton_dynamic_range_write_clicked()
{
    const char* pcData = ui->cmb_dynamic_ranges->currentText().toStdString().c_str();
    serialPort.write(pcData);

    disable_all_widgets();
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_dynamic_range_set->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_calibrate_device->setEnabled(true);
}

void MainWindow::on_pushButton_calibrate_device_clicked()
{
    serialPort.write(CMD_CALIBRATE_DEVICE);
}

void MainWindow::on_pushButton_COM_connect_clicked()
{
    if(buttonState == COM_PORT_DISCONNECTED)
    {
        QString numStr;

        /* finding a double value in the string */
        foreach(numStr, ui->comboBox_port->currentText().split(" ", QString::SkipEmptyParts))
        {
            if(numStr.contains("COM")) break;
            else continue;
        }

        serialPort.setPortName(numStr);
        serialPort.setBaudRate(QSerialPort::Baud9600);
        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setParity(QSerialPort::NoParity);
        serialPort.setStopBits(QSerialPort::OneStop);
        serialPort.setFlowControl(QSerialPort::NoFlowControl);

        if (!serialPort.open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
            return;
        }
        else
        {
            connect(&serialPort, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
            buttonState = COM_PORT_CONNECTED;
            ui->pushButton_COM_connect->setText(QString::fromUtf8("Отключиться"));
            serialPort.write("0000");
            serialPort.waitForBytesWritten(10);
        }
    }
    else if(buttonState == COM_PORT_CONNECTED)
    {
        ui->pushButton_COM_connect->setText(QString::fromUtf8("Подключиться"));
        serialPort.close();
        buttonState = COM_PORT_DISCONNECTED;
        ui->comboBox_port->clear();
        foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
        {
            ui->comboBox_port->addItem(QString("%1 (%2)").arg(serialPortInfo.portName(), serialPortInfo.description()));
        }
    }
}

void MainWindow::plotGraph(QString msg)
{
    QString value;

    /* finding a double value in the string */
    foreach(QString numStr, msg.split(" ", QString::SkipEmptyParts))
    {
        if(numStr == "[INFO]" || numStr == "[INIT]" || numStr == "[ERROR]") return;
        bool check = false;
        numStr.toDouble(&check);
        if(check) value = numStr;
        else continue;
    }

    counter++;
    X_Axis.append(counter);
    Y_Axis.append(value.toDouble());

    ui->canvas->graph(0)->setData(X_Axis, Y_Axis);
    ui->canvas->graph(0)->rescaleAxes(true);
    ui->canvas->replot();
    ui->canvas->update();
}

void MainWindow::receiveMessage()
{
    QString code = "***";
    int codeSize = code.size();
    QByteArray dataBA = serialPort.readAll();
    QString data(QString::fromUtf8(dataBA));
    serialBuffer.append(data);
    int index = serialBuffer.indexOf(code);

    if(index != -1)
    {
        QString message = serialBuffer.mid(0, index);
        printConsole(message);
        plotGraph(message);
        serialBuffer.remove(0, index + codeSize);
    }
}

void MainWindow::printConsole(QString string)
{
    ui->UART_output->setTextColor(Qt::blue); // Received message's color is blue.
    ui->UART_output->append(QTime::currentTime().toString("HH:mm:ss.zzz    |  ") + string);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Control:
        on_pushButton_clear_console_clicked();
        break;
        case Qt::Key_Alt:
        on_pushButton_clear_canvas_clicked();
        break;
    }
}

void MainWindow::on_pushButton_clear_canvas_clicked()
{
    X_Axis.clear();
    Y_Axis.clear();
    ui->canvas->graph(0)->setData(X_Axis, Y_Axis);
    ui->canvas->graph(0)->rescaleAxes(true);
    ui->canvas->replot();
    ui->canvas->update();
}

void MainWindow::on_pushButton_clear_console_clicked()
{
    ui->UART_output->clear();
}
