#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

#define CMD_DL_CALIBRATION "DLSS"
#define CMD_DL_WRITE "DLW"
#define CMD_UL_CALIBRATION "ULSS"
#define CMD_UL_WRITE "ULWW"
#define CMD_MMPS_SET "MMSS"
#define CMD_MMPS_WRITE "MMW"
#define CMD_FLASH_WRITE "WSTF"
#define CMD_MCU_RESTART "REST"

void MainWindow::disable_all_widgets()
{
    ui->pushButton_DL_calibration->setEnabled(false);
    ui->pushButton_DL_multimeter->setEnabled(false);
    ui->pushButton_DL_write->setEnabled(false);
    ui->pushButton_UL_calibration->setEnabled(false);
    ui->pushButton_UL_multimeter->setEnabled(false);
    ui->pushButton_UL_write->setEnabled(false);
    ui->pushButton_mmpersec_calibration->setEnabled(false);
    ui->pushButton_mmpersec_write->setEnabled(false);
    ui->pushButton_flash_write->setEnabled(false);
    ui->lineEdit_DL_value->setEnabled(false);
    ui->lineEdit_UL_value->setEnabled(false);
    ui->cmb_mmpersec->setEnabled(false);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(serialPortInfo.portName());
    }

    this->setWindowTitle(QString::fromUtf8("ВД17 - Настройки"));

    ui->lineEdit_DL_value->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));
    ui->lineEdit_UL_value->setValidator(new QRegExpValidator(QRegExp("[0-9]\\d{0,3}"), this));

    ui->cmb_mmpersec->addItem("020");
    ui->cmb_mmpersec->addItem("050");
    ui->cmb_mmpersec->addItem("100");
    ui->cmb_mmpersec->addItem("200");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_DL_calibration_clicked()
{
    disable_all_widgets();
    ui->lineEdit_DL_value->setEnabled(true);
    ui->pushButton_DL_multimeter->setEnabled(true);
    ui->pushButton_DL_write->setEnabled(true);

    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    serialPort.write(CMD_DL_CALIBRATION);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();
}

void MainWindow::on_pushButton_DL_multimeter_clicked()
{
    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

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

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();
}

void MainWindow::on_pushButton_DL_write_clicked()
{
    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    serialPort.write(CMD_DL_WRITE);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();

    disable_all_widgets();
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_flash_write->setEnabled(true);
}

void MainWindow::on_pushButton_UL_calibration_clicked()
{
    disable_all_widgets();
    ui->lineEdit_UL_value->setEnabled(true);
    ui->pushButton_UL_multimeter->setEnabled(true);
    ui->pushButton_UL_write->setEnabled(true);

    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    serialPort.write(CMD_UL_CALIBRATION);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();
}

void MainWindow::on_pushButton_UL_multimeter_clicked()
{
    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    if(ui->lineEdit_UL_value->text().size() == 0)
    {
        QString str_temp = "1576";
        ui->lineEdit_UL_value->setText(str_temp);
    }
    else if(ui->lineEdit_UL_value->text().size() == 1)
    {
        QString str_temp = ui->lineEdit_UL_value->text();
        str_temp = "000" + str_temp;
        ui->lineEdit_UL_value->setText(str_temp);
    }
    else if(ui->lineEdit_UL_value->text().size() == 2)
    {
        QString str_temp = ui->lineEdit_UL_value->text();
        str_temp = "00" + str_temp;
        ui->lineEdit_UL_value->setText(str_temp);
    }
    else if(ui->lineEdit_UL_value->text().size() == 3)
    {
        QString str_temp = ui->lineEdit_UL_value->text();
        str_temp = "0" + str_temp;
        ui->lineEdit_UL_value->setText(str_temp);
    }

    const char* pcData = ui->lineEdit_UL_value->text().toStdString().c_str();
    serialPort.write(pcData);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();
}

void MainWindow::on_pushButton_UL_write_clicked()
{
    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    serialPort.write(CMD_UL_WRITE);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();

    disable_all_widgets();
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_flash_write->setEnabled(true);
}

void MainWindow::on_pushButton_mmpersec_calibration_clicked()
{
    disable_all_widgets();
    ui->cmb_mmpersec->setEnabled(true);
    ui->pushButton_mmpersec_write->setEnabled(true);

    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    serialPort.write(CMD_MMPS_SET);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();

}

void MainWindow::on_pushButton_mmpersec_write_clicked()
{
    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    const char* pcData = ui->cmb_mmpersec->currentText().toStdString().c_str();
    serialPort.write(pcData);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.write(CMD_MMPS_WRITE);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();

    disable_all_widgets();
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_flash_write->setEnabled(true);
}


void MainWindow::on_pushButton_flash_write_clicked()
{
    QSerialPort serialPort;

    serialPort.setPortName(ui->comboBox_port->currentText().toStdString().c_str());
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);

    QByteArray data;

    if (!serialPort.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
        return;
    }

    serialPort.write(CMD_FLASH_WRITE);

    while (serialPort.waitForReadyRead(100)) {
        data.append(serialPort.readAll());
    }

    ui->UART_output->append(data);

    serialPort.close();
}
