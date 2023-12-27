#include <mainwindow.h>
#include <ui_mainwindow.h>


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
    ui->pushButton_thermoslope_set->setEnabled(false);
    ui->pushButton_thermoslope_write->setEnabled(false);
    ui->pushButton_thermointercept_set->setEnabled(false);
    ui->pushButton_thermointercept_write->setEnabled(false);
    ui->pushButton_constant_value_set->setEnabled(false);
    ui->pushButton_constant_value_write->setEnabled(false);
    ui->pushButton_default_settings_set->setEnabled(false);

    ui->lineEdit_DL_value->setEnabled(false);
    ui->lineEdit_UL_value->setEnabled(false);
    ui->lineEdit_mmpersec_value->setEnabled(false);
    ui->lineEdit_thermoslope->setEnabled(false);
    ui->lineEdit_thermointercept->setEnabled(false);
    ui->lineEdit_constant_value->setEnabled(false);

    ui->cmb_dynamic_ranges->setEnabled(false);

}

void MainWindow::reset_all_widgets()
{
    disable_all_widgets();

    ui->pushButton_DL_calibration->setEnabled(true);
    ui->pushButton_UL_calibration->setEnabled(true);
    ui->pushButton_mmpersec_calibration->setEnabled(true);
    ui->pushButton_dynamic_range_set->setEnabled(true);
    ui->pushButton_thermoslope_set->setEnabled(true);
    ui->pushButton_thermointercept_set->setEnabled(true);
    ui->pushButton_constant_value_set->setEnabled(true);
    ui->pushButton_calibrate_device->setEnabled(true);
    ui->pushButton_default_settings_set->setEnabled(true);
}


void MainWindow::printConsole(const QString& string)
{
    QString message = string;
    QString time = QTime::currentTime().toString("HH:mm:ss.zzz    |  ");
    if(string.contains('\r')) time = "";

    ui->UART_output->setTextColor(Qt::blue); // Received message's color is blue.
    ui->UART_output->append(time + message);
}

void MainWindow::slotClearCanvas()
{
    counter = 0;
    flagMeasureDone = 0;
    valueA = 0;
    valueV = 0;
    valueT = 0;
    serialBuffer.clear();

    ui->canvas->clearGraphs();
    ui->canvas->replot();
    ui->canvas->rescaleAxes();

    ui->canvas->xAxis->setRange(0, 1);
    ui->canvas->yAxis->setRange(0, 1);

    ui->lineEdit_RMS_A->clear();
    ui->lineEdit_RMS_V->clear();
    ui->lineEdit_RMS_T->clear();

    ui->lineEdit_average_A->clear();
    ui->lineEdit_average_V->clear();
    ui->lineEdit_average_T->clear();

    ui->canvas->update();
}

void MainWindow::slotClearConsole()
{
    ui->UART_output->clear();
}

void MainWindow::slotClearAll()
{
    slotClearCanvas();
    slotClearConsole();
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
        QMessageBox::critical(this, "Ошибка", "Файл не найден или поврежден");
    }

    QSize mainWindowSize = this->size();
    historyDialog->resize(mainWindowSize);

    historyDialog->show();
}

bool MainWindow::serialPortCheckout()
{
    bool findSerialCOM = false;
    QString text1 = "prolific";
    QString text2 = "123";
    QString text3 = "moxa";

    QStringList availablePorts; // Список доступных COM-портов

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        QString name = serialPortInfo.portName();
        QString description = serialPortInfo.description();

        availablePorts.append(QString("%1 (%2)").arg(name, description));
    }

    // Удаление COM-портов, которых уже нет в системе
    for (int i = ui->comboBox_port->count() - 1; i >= 0; --i)
    {
        QString portName = ui->comboBox_port->itemText(i);
        if (!availablePorts.contains(portName))
        {
            if(ui->comboBox_port->currentIndex() == i && buttonState == COM_PORT_CONNECTED)
            {
                on_pushButton_COM_connect_clicked();
            }
            ui->comboBox_port->removeItem(i);
        }
    }

    // Добавление новых COM-портов в комбобокс
    foreach (const QString &portName, availablePorts)
    {
        if (ui->comboBox_port->findText(portName) == -1) // Проверка наличия порта в комбобоксе
        {
            ui->comboBox_port->addItem(portName);
        }
    }

    for (int i = 0; i < ui->comboBox_port->count(); ++i)
    {
        QString itemText = ui->comboBox_port->itemText(i);
        if(itemText.contains(text1, Qt::CaseInsensitive) || itemText.contains(text2, Qt::CaseInsensitive) || itemText.contains(text3, Qt::CaseInsensitive))
        {
            ui->comboBox_port->setCurrentIndex(i);
            findSerialCOM = true;
        }
    }

    return findSerialCOM;
}

/* Сохраняем настройки в приложение */
void MainWindow::saveAppSettings(appSettingsStruct tempSettings)
{
    /* Путь до настроек в .ini формате */
    QSettings settingsQt(QApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);

    settingsQt.beginGroup("settings");
    settingsQt.setValue("baudRate", tempSettings.baudRate);
    settingsQt.setValue("bufferSize", tempSettings.bufferSize);
    settingsQt.setValue("messageCode", tempSettings.messageCode);
    settingsQt.setValue("dataBits", tempSettings.dataBits);
    settingsQt.setValue("parityControl", tempSettings.parityControl);
    settingsQt.setValue("stopBits", tempSettings.stopBits);
    settingsQt.setValue("flowControl", tempSettings.flowControl);
    settingsQt.endGroup();

    settingsQt.sync();

    initializeAppSettings();
}

void MainWindow::initializeAppSettings()
{
    /* Путь до настроек в .ini формате */
    QSettings settingsQt(QApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);
    appSettingsStruct tempStruct;

    settingsQt.beginGroup("settings");

    baudRate_ = static_cast<QSerialPort::BaudRate>(settingsQt.value("baudRate", 115200).toInt());
    bufferSize_ = settingsQt.value("bufferSize", 32).toInt();
    messageCode_ = settingsQt.value("messageCode", "***").toString();
    dataBits_ = static_cast<QSerialPort::DataBits>(settingsQt.value("dataBits", 8).toInt());

    QString tempParity = settingsQt.value("parityControl", "Не используется").toString();
    if(tempParity == "Не используется") parityControl_ = QSerialPort::NoParity;
    else if(tempParity == "Четность") parityControl_ = QSerialPort::EvenParity;
    else if(tempParity == "Нечетность") parityControl_ = QSerialPort::OddParity;
    else if(tempParity == "Пространственный") parityControl_ = QSerialPort::SpaceParity;
    else if(tempParity == "Маркировочный") parityControl_ = QSerialPort::MarkParity;

    QString tempStopBits = settingsQt.value("stopBits", "1").toString();
    if(tempStopBits == "1") stopBits_ = QSerialPort::OneStop;
    else if(tempStopBits == "1.5") stopBits_ = QSerialPort::OneAndHalfStop;
    else if(tempStopBits == "2") stopBits_ = QSerialPort::TwoStop;

    QString tempFlowControl = settingsQt.value("flowControl", "Не используется").toString();
    if (tempFlowControl == "Не используется") flowControl_ = QSerialPort::NoFlowControl;
    else if (tempFlowControl == "Аппаратный") flowControl_ = QSerialPort::HardwareControl;
    else if (tempFlowControl == "Программный") flowControl_ = QSerialPort::SoftwareControl;

    settingsQt.endGroup();

    cbA.resize(bufferSize_);
    cbV.resize(bufferSize_);
    cbT.resize(bufferSize_);

    tempStruct.baudRate = QString::number(baudRate_);
    tempStruct.bufferSize = QString::number(bufferSize_);
    tempStruct.messageCode = QString(messageCode_);
    tempStruct.dataBits = QString::number(dataBits_);
    tempStruct.parityControl = QString::number(parityControl_);
    tempStruct.stopBits = QString::number(stopBits_);
    tempStruct.flowControl = QString::number(flowControl_);

    emit setSettingsUI(tempStruct);
}

void MainWindow::initializeMenu()
{
    /* Меню для взаимодействия с графиком */
    QMenu* menuClear = new QMenu(tr("Меню взаимодействия с графиком"));
    menuClear->addAction(tr("Очистить консоль"),  this, SLOT(slotClearConsole()));
    menuClear->addAction(tr("Очистить график"), this, SLOT(slotClearCanvas()));
    menuClear->addAction(tr("Очистить всё"), this, SLOT(slotClearAll()));
    ui->menuClear->setMenu(menuClear);
}

void MainWindow::initializeCanvas()
{
    /* Настройка холста, на котором будет отрисовываться график
       Разрешаем зум и перемещение по графику */
    ui->canvas->setInteraction(QCP::iRangeDrag, true);
    ui->canvas->setInteraction(QCP::iRangeZoom, true);
    ui->canvas->xAxis->setLabel("Точки отсчета");
    ui->canvas->yAxis->setLabel("A, V");
}

void MainWindow::initializeConnects()
{
    /* Коннекты связей между плоттером графиков и GUI */
    connect(ui->canvas, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(slotMouseMove(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(slotMouseDoubleClick(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(slotMousePress(QMouseEvent*)));
    connect(ui->canvas, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(slotMouseRelease(QMouseEvent*)));

    connect(&settingsUI_, SIGNAL(needSaveSettings(appSettingsStruct)), this, SLOT(saveAppSettings(appSettingsStruct)));
    connect(this, SIGNAL(setSettingsUI(appSettingsStruct)), &settingsUI_, SLOT(setVisibleSettings(appSettingsStruct)));

    connect(&serialTimer, SIGNAL(timeout()), this, SLOT(serialPortCheckout()));
}

// Debug
void MainWindow::serialGetConfig()
{
    // Successfully connected
    qDebug() << "baudRate:" << serialPort->baudRate();
    qDebug() << "parity:" << serialPort->parity();
    qDebug() << "stopBits:" << serialPort->stopBits();
    qDebug() << "dataBits:" << serialPort->dataBits();
    qDebug() << "flowControl:" << serialPort->flowControl();
}
