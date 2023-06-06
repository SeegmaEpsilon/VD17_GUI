#include "mainwindow.h"
#include "ui_mainwindow.h"

#define CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION "DL" // calibration of down limit current loop (4mA)
#define CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION "UL"   // calibration of up limit current loop (20mA)
#define CMD_DYNAMIC_MODE_SET "DR"                    // setting dynamic range of accelerometer
#define CMD_MM_PER_SEC_SET "MV"                      // setting max mm/s of device
#define CMD_CALIBRATE_DEVICE "CD"                    // calibrate the device (10.1 m/s^2)

#define CMD_DOWN_LIMIT_CURRENT_LOOP_WRITE "DLWW"
#define CMD_UP_LIMIT_CURRENT_LOOP_WRITE "ULWW"
#define CMD_MM_PER_SEC_WRITE "MMW"
#define CMD_DYNAMIC_MODE_WRITE "MW"
#define CMD_FLASH_WRITE "WS"

enum BUTTON_STATE
{
    COM_PORT_DISCONNECTED = 0,
    COM_PORT_CONNECTED = 1
};

int buttonState = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    counter = 0;
    valueA = 0;
    valueV = 0;
    highlightedIndex = 0;
    flagMeasureDone = 0;

    averageBufferA.resize(16);
    averageBufferA.resize(16);

    connect(&timer, SIGNAL(timeout()), this, SLOT(slotTimerTimeout()));
    timer.start(500);

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(QString("%1 (%2)").arg(serialPortInfo.portName(), serialPortInfo.description()));
    }

    QString textToFind = "Prolific";
    int index = ui->comboBox_port->findText(textToFind, Qt::MatchContains);

    if(index != -1)
    {
      ui->comboBox_port->setCurrentIndex(index);
    }

    this->setWindowTitle(QString::fromUtf8("ВД17-Сервис v1.9"));

    ui->canvas->setInteraction(QCP::iRangeDrag, true);
    ui->canvas->setInteraction(QCP::iRangeZoom, true);
    ui->canvas->xAxis->setLabel("Точки отсчета");
    ui->canvas->yAxis->setLabel("A, V");

    disable_all_widgets();
}

MainWindow::~MainWindow()
{
    serialPort.close();
    delete ui;
}


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

void MainWindow::enable_all_widgets()
{
    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_DL_multimeter->setEnabled(true);
    ui->pushButton_DL_write->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_UL_multimeter->setEnabled(true);
    ui->pushButton_UL_write->setEnabled(true);
    ui->pushButton_dynamic_range_set->setEnabled(true);
    ui->pushButton_dynamic_range_write->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_mmpersec_write->setEnabled(true);
    ui->pushButton_calibrate_device->setEnabled(true);
    ui->lineEdit_DL_value->setEnabled(true);
    ui->lineEdit_UL_value->setEnabled(true);
    ui->cmb_mmpersec->setEnabled(true);
    ui->cmb_dynamic_ranges->setEnabled(true);
}

void MainWindow::reset_all_widgets()
{
  disable_all_widgets();
  enable_all_widgets();

  ui->lineEdit_DL_value->setEnabled(false);
  ui->pushButton_DL_multimeter->setEnabled(false);
  ui->pushButton_DL_write->setEnabled(false);

  ui->lineEdit_UL_value->setEnabled(false);
  ui->pushButton_UL_multimeter->setEnabled(false);
  ui->pushButton_UL_write->setEnabled(false);

  ui->cmb_mmpersec->setEnabled(false);
  ui->pushButton_mmpersec_write->setEnabled(false);

  ui->cmb_dynamic_ranges->setEnabled(false);
  ui->pushButton_dynamic_range_write->setEnabled(false);
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
    QString str_temp = ui->lineEdit_DL_value->text();

    switch(str_temp.size())
    {
      case 0:
          str_temp = "0100";
          ui->lineEdit_DL_value->setValue(str_temp.toInt());
          break;
      case 1:
          str_temp = "000" + str_temp;
          break;
      case 2:
          str_temp = "00" + str_temp;
          break;
      case 3:
          str_temp = "0" + str_temp;
          break;
    }

    const char* pcData = str_temp.toStdString().c_str();
    serialPort.write(pcData);
}

void MainWindow::on_pushButton_DL_write_clicked()
{
    serialPort.write(CMD_DOWN_LIMIT_CURRENT_LOOP_WRITE);
    reset_all_widgets();
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
    QString str_temp = ui->lineEdit_UL_value->text();
    switch(str_temp.size())
    {
      case 0:
          str_temp = "1580";
          ui->lineEdit_UL_value->setValue(str_temp.toInt());
          break;
      case 1:
          str_temp = "000" + str_temp;
          break;
      case 2:
          str_temp = "00" + str_temp;
          break;
      case 3:
          str_temp = "0" + str_temp;
          break;
    }

    const char* pcData = str_temp.toStdString().c_str();
    serialPort.write(pcData);
}

void MainWindow::on_pushButton_UL_write_clicked()
{
    serialPort.write(CMD_UP_LIMIT_CURRENT_LOOP_WRITE);
    reset_all_widgets();
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
    QString serialData;
    if(ui->cmb_mmpersec->currentIndex() == 0) serialData = "020";
    if(ui->cmb_mmpersec->currentIndex() == 1) serialData = "050";
    if(ui->cmb_mmpersec->currentIndex() == 2) serialData = "100";
    if(ui->cmb_mmpersec->currentIndex() == 3) serialData = "200";

    const char* pcData = serialData.toStdString().c_str();
    serialPort.write(pcData);
    reset_all_widgets();
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
    reset_all_widgets();
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

        if (!serialPort.open(QIODevice::ReadWrite))
        {
            QMessageBox::warning(this, QString::fromUtf8("Ошибка"), QString::fromUtf8("Выбранный порт недоступен"));
            return;
        }
        else
        {
            serialPort.setBaudRate(QSerialPort::Baud115200);
            serialPort.setDataBits(QSerialPort::Data8);
            serialPort.setParity(QSerialPort::NoParity);
            serialPort.setStopBits(QSerialPort::OneStop);
            serialPort.setFlowControl(QSerialPort::NoFlowControl);

            buttonState = COM_PORT_CONNECTED;
            ui->pushButton_COM_connect->setText(QString::fromUtf8("Отключиться"));

            reset_all_widgets();
            connect(&serialPort, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
        }
    }
    else if(buttonState == COM_PORT_CONNECTED)
    {
        ui->pushButton_COM_connect->setText(QString::fromUtf8("Подключиться"));
        serialPort.close();
        buttonState = COM_PORT_DISCONNECTED;
        disable_all_widgets();
    }
}

void MainWindow::plotGraph(QString &msg)
{
    uint8_t flag_select_value = 0;

    /* finding a double value in the string */
    foreach(QString numStr, msg.split(" ", QString::SkipEmptyParts))
    {
        if(numStr == "A(RMS)") flag_select_value = 1;
        if(numStr == "V(RMS)") flag_select_value = 2;

        bool check = false;
        numStr.toDouble(&check);
        if(check)
        {
            if(flag_select_value == 1)
            {
                flagMeasureDone = 1;
                valueA = numStr.toDouble();
            }
            if(flag_select_value == 2)
            {
                if(flagMeasureDone == 1) flagMeasureDone = 2;
                valueV = numStr.toDouble();
            }
        }
        else continue;
    }

    if(flagMeasureDone == 2)
    {
        flagMeasureDone = 0;

        static CircularBuffer cbA(32);
        static CircularBuffer cbV(32);

        cbA.push(valueA);
        cbV.push(valueV);

        ui->lineEdit_RMS_A->setText(QString::number(valueA, 'f', 2));
        ui->lineEdit_RMS_V->setText(QString::number(valueV, 'f', 2));

        ui->lineEdit_average_A->setText(QString::number(cbA.average(), 'f', 2));
        ui->lineEdit_average_V->setText(QString::number(cbV.average(), 'f', 2));

        if(ui->checkBox_need_plot->isChecked() == false) return;
        counter++;

        if(ui->canvas->graphCount() < 2)
        {
          ui->canvas->addGraph();
          ui->canvas->addGraph();
        }

        ui->canvas->legend->setVisible(true);
        QFont legendFont = font();
        legendFont.setPointSize(8);
        ui->canvas->legend->setFont(legendFont);
        ui->canvas->legend->setBrush(QBrush(QColor(255,255,255,230)));

        ui->canvas->graph(0)->setName("Виброускорение (СКЗ)");
        ui->canvas->graph(0)->setPen(QPen(Qt::blue));
        ui->canvas->graph(0)->addData(counter, valueA);
        ui->canvas->graph(0)->rescaleAxes(true);

        ui->canvas->graph(1)->setName("Виброскорость (СКЗ)");
        ui->canvas->graph(1)->setPen(QPen(Qt::red));
        ui->canvas->graph(1)->addData(counter, valueV);
        ui->canvas->graph(1)->rescaleAxes(true);

        ui->canvas->replot();
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
        if(message.contains("[DEBUG]"))
        {
          plotGraph(message);
        }
        else if(message.contains("[INIT]"))
        {
            printConsole(message);
            reset_all_widgets();
            if(message.contains("Correction ratio of 4mA"))
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
            else if(message.contains("Correction ratio of 20mA"))
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
            else if(message.contains("Max mm per sec"))
            {
                foreach(QString numStr, message.split(" ", QString::SkipEmptyParts))
                {
                    int index = ui->cmb_mmpersec->findText(numStr, Qt::MatchContains);
                    if(index != -1) ui->cmb_mmpersec->setCurrentIndex(index);
                }
            }
            else if(message.contains("Dynamic range"))
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

void MainWindow::printConsole(const QString& string)
{
    ui->UART_output->setTextColor(Qt::blue); // Received message's color is blue.
    ui->UART_output->append(QTime::currentTime().toString("HH:mm:ss.zzz    |  ") + string);
}

void MainWindow::on_pushButton_clear_canvas_clicked()
{
    counter = 0;
    flagMeasureDone = 0;
    valueA = 0;
    valueV = 0;

    serialBuffer.clear();

    ui->canvas->clearGraphs();
    ui->canvas->replot();
    ui->canvas->rescaleAxes();

    ui->canvas->xAxis->setRange(0, 1);
    ui->canvas->yAxis->setRange(0, 1);

    ui->lineEdit_RMS_A->clear();
    ui->lineEdit_RMS_V->clear();
    ui->lineEdit_average_A->clear();
    ui->lineEdit_average_V->clear();

    ui->canvas->update();
}

void MainWindow::on_pushButton_clear_console_clicked()
{
    ui->UART_output->clear();
}

void MainWindow::slotTimerTimeout()
{
    if(highlightedIndex || ui->comboBox_port->underMouse())
    {
        highlightedIndex = 0;
        return;
    }
    QString previous_name = ui->comboBox_port->currentText();
    ui->comboBox_port->clear();
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(QString("%1 (%2)").arg(serialPortInfo.portName(), serialPortInfo.description()));
    }
    ui->comboBox_port->setCurrentIndex(ui->comboBox_port->findText(previous_name));
    if(ui->comboBox_port->currentText().isEmpty() && buttonState == COM_PORT_CONNECTED)
    {
        on_pushButton_COM_connect_clicked();
    }
}

void MainWindow::on_comboBox_port_highlighted(const int &index)
{
    highlightedIndex = index;
}

void MainWindow::on_pushButton_manual_clicked()
{
  QDialog* historyDialog = new QDialog(this);

  historyDialog->setWindowTitle("Инструкция по настройке");

  QTextEdit* historyTextEdit = new QTextEdit(historyDialog);
  QVBoxLayout* layout = new QVBoxLayout(historyDialog);
  layout->addWidget(historyTextEdit);
  historyTextEdit->setReadOnly(true);

  QFile file(QApplication::applicationDirPath() + "/Инструкция.txt");
  if(file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
      QString content = file.readAll();
      historyTextEdit->append(content);
  }
  else
  {
    qDebug() << "File cannot be open";
  }

  QSize mainWindowSize = this->size();
  historyDialog->resize(mainWindowSize);

  historyDialog->show();
}
