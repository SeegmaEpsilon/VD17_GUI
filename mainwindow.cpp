#include "mainwindow.h"
#include "ui_mainwindow.h"

#define CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION "D" // calibration of down limit current loop (4mA)
#define CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION "U"   // calibration of up limit current loop (20mA)
#define CMD_DYNAMIC_MODE_SET "M"                    // setting dynamic range of accelerometer
#define CMD_MM_PER_SEC_SET "V"                      // setting max mm/s of device
#define CMD_CALIBRATE_DEVICE "C"                    // calibrate the device (10.1 m/s^2)
#define CMD_GET_CONFIG "G"                          // get config data

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

    connect(&timer, SIGNAL(timeout()), this, SLOT(slotTimerTimeout()));
    timer.start(500);

    highlighted_index = 0;
    flag_measure_done = 0;
    counter = 0;

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(QString("%1 (%2)").arg(serialPortInfo.portName(), serialPortInfo.description()));
    }

    this->setWindowTitle(QString::fromUtf8("ВД17-Сервис v1.7"));

    ui->canvas->setInteraction(QCP::iRangeDrag, true);
    ui->canvas->setInteraction(QCP::iRangeZoom, true);
    ui->canvas->xAxis->setLabel("t");
    ui->canvas->yAxis->setLabel("V, A");

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
    ui->pushButton_get_config->setEnabled(false);
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
    ui->pushButton_get_config->setEnabled(true);
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

void MainWindow::plotGraph(QString msg)
{
    QString value;

    unsigned int flag_select_value = 0;

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
                flag_measure_done++;
                value = numStr;
                ui->lineEdit_RMS_A->setText(QString(value));
                Y_Acceleration.append(value.toDouble());
            }
            if(flag_select_value == 2)
            {
                flag_measure_done++;
                value = numStr;
                ui->lineEdit_RMS_V->setText(QString(value));
                Y_Velocity.append(value.toDouble());
            }
        }
        else continue;
    }

    if(flag_measure_done == 2)
    {
        counter++;
        X_Acceleration.append(counter);
        X_Velocity.append(counter);
        flag_measure_done = 0;
    }

    if(!Y_Acceleration.isEmpty())
    {
        double average_A = 0.0f;
        for(int i = 0; i < Y_Acceleration.size(); i++) average_A += Y_Acceleration[i];
        average_A /= Y_Acceleration.size();
        ui->lineEdit_average_A->setText(QString::number(average_A, 'f', 2));
    }

    if(!Y_Velocity.isEmpty())
    {
        double average_V = 0.0f;
        for(int i = 0; i < Y_Velocity.size(); i++) average_V += Y_Velocity[i];
        average_V /= Y_Velocity.size();
        ui->lineEdit_average_V->setText(QString::number(average_V, 'f', 2));
    }

    ui->canvas->clearGraphs();
    ui->canvas->legend->clear();
    ui->canvas->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(8);
    ui->canvas->legend->setFont(legendFont);
    ui->canvas->legend->setBrush(QBrush(QColor(255,255,255,230)));

    ui->canvas->addGraph();
    ui->canvas->graph(0)->setName("Acceleration (RMS)");
    ui->canvas->graph(0)->setPen(QPen(Qt::blue));
    ui->canvas->graph(0)->setData(X_Acceleration, Y_Acceleration);
    ui->canvas->graph(0)->rescaleAxes(true);

    ui->canvas->addGraph();
    ui->canvas->graph(1)->setName("Velocity (RMS)");
    ui->canvas->graph(1)->setPen(QPen(Qt::red));
    ui->canvas->graph(1)->setData(X_Velocity, Y_Velocity);
    ui->canvas->graph(1)->rescaleAxes(true);

    ui->canvas->replot();
    ui->canvas->update();
}

void MainWindow::receiveMessage()
{
    QString code = "***";
    int codeSize = code.size();

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
            if(message.contains("Correction ratio of 20mA"))
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
            if(message.contains("Max mm per sec"))
            {
                foreach(QString numStr, message.split(" ", QString::SkipEmptyParts))
                {
                    int index = ui->cmb_mmpersec->findText(numStr, Qt::MatchContains);
                    if(index != -1) ui->cmb_mmpersec->setCurrentIndex(index);
                }
            }
            if(message.contains("Dynamic range"))
            {
                foreach(QString numStr, message.split(" ", QString::SkipEmptyParts))
                {
                    int index = ui->cmb_dynamic_ranges->findText(numStr);
                    if(index != -1) ui->cmb_dynamic_ranges->setCurrentIndex(index);
                }
            }
        }
        else
        {
            printConsole(message);
        }
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
    counter = 0;
    flag_measure_done = 0;

    serialData.clear();
    serialBuffer.clear();
    serialList.clear();

    X_Acceleration.clear();
    Y_Acceleration.clear();

    X_Velocity.clear();
    Y_Velocity.clear();

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
    if(highlighted_index || ui->comboBox_port->underMouse())
    {
        highlighted_index = 0;
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

void MainWindow::on_comboBox_port_highlighted(int index)
{
    highlighted_index = index;
}

void MainWindow::on_pushButton_get_config_clicked()
{
    serialPort.write(CMD_GET_CONFIG);
}

void MainWindow::on_pushButton_manual_clicked()
{
  QString instruction = QString("1 Закрепите датчик на вибростоле.\n\n"
                        "2 Подведите провода питания к датчику, подключите по схеме, само питание не включайте. Наличие миллиамперметра обязательно.\n\n"
                        "3 Подсоедините переходник USB-UART сначала к компьютеру, потом к датчику.\n\n"
                        "4 В программе, в выпадающем окне рядом с надписью \"COM-Порт\", выберете COM-порт используемого UART-преобразователя.\n\n"
                        "5 Нажмите кнопку \"Подключиться\".\n\n"
                        "6 Подайте питание на датчик. \nВНИМАНИЕ: Блок питания должен быть ОБЯЗАТЕЛЬНО заземлен и настроен на 24 вольта.\n\n"
                        "7 В случае успешного подключения в консоли приложения будет показана текущая конфигурация датчика и начнет строиться график в правой части интерфейса.\n"
                        "Если этого не произошло, начните с шага 2.\n\n"
                        "8 Откалибруйте нижний предел токовой петли.\n"
                        "Для этого необходимо подобрать такое число, при котором значение тока на миллиамперметре будет в районе 4.1 миллиампера (мА):\n"
                        "8.1 Нажмите на кнопку \"Калибровка нижнего предела ТП\".\n"
                        "8.2 В случае начала калибровки нижнего предела ТП датчик отправит соответствующее сообщение в консоль.\n"
                        "Если этого не произошло, начните с шага 2.\n"
                        "8.3 Введите число в разблокировавшемся окне и нажмите кнопку \"Мультиметр\".\n"
                        "8.4 Сравните текущее значение тока на миллиамперметре с необходимым (4.1 мА), "
                        "если ток больше необходимого значения, уменьшите число, если ниже - увеличьте число и снова нажмите \"Мультиметр\".\n"
                        "8.5 Когда значение на миллиамперметре совпадет с необходимым (4.1 мА), нажмите кнопку \"Записать\".\n\n"
                        "9 Настройку верхнего предела токовой петли проведите так же, как и нижнего, но теперь необходимое значение тока на миллиамперметре будет 20.1 миллиампер (мА).\n\n"
                        "10 Выберете значение виброскорости, которое будет соответствовать значению тока в 20 мА.\n"
                        "Для этого нажмите на кнопку \"Установка максимальной виброскорости\", из разблокировавшегося выпадающего списка выберете нужное значение и нажмите кнопку \"Записать\".\n\n"
                        "11 Выберете динамический диапазон акселерометра.\n"
                        "Для этого нажмите на кнопку \"Установка динамического диапазона\", из разблокировавшегося выпадающего списка выберете нужное значение и нажмите кнопку \"Записать\".\n\n"
                        "12 Для калибровки датчика необходимо:\n"
                        "12.1 Включить вибростол.\n"
                        "12.2 Подождать, пока датчик выйдет на режим. Датчик выйдет на режим, когда на графике в правой части интерфейса синия и красная линии перестанут расти и станут околопрямой линией.\n"
                        "12.3 Нажать на кнопку \"Калибровать датчик\".");

  QDialog *msgDialog = new QDialog();
  QLayout *layout = new QVBoxLayout();
  QLabel *label = new QLabel(instruction);

  label->setTextInteractionFlags(Qt::TextSelectableByMouse);
  label->setStyleSheet("QLabel{border: 1px solid gray;background-color:rgba(255, 255, 255, 20);border-radius: 5px;}");
  layout->addWidget(label);

  msgDialog->setLayout(layout);
  msgDialog->setWindowTitle(tr("Инструкция по настройке ВД17"));
  msgDialog->open();
}
