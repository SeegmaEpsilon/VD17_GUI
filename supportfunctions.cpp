#include <mainwindow.h>
#include <ui_mainwindow.h>

void MainWindow::printConsole(const QString& string)
{
  QString message = string;
  QString time = QTime::currentTime().toString("HH:mm:ss.zzz    |  ");
  if (string.contains('\r') || string.contains('\n'))
    time = "";

  ui->UART_output->setTextColor(Qt::blue); // Received message's color is blue.
  ui->UART_output->append(time + message);
}

void MainWindow::slotClearCanvas()
{
  flagMeasureDone = 0;
  valueA = 0;
  valueV = 0;
  valueT = 0;
  counterA = 0;
  counterV = 0;
  serialBuffer.clear();

  ui->canvas_A->clearGraphs();
  ui->canvas_A->replot();
  ui->canvas_A->rescaleAxes();

  ui->canvas_V->clearGraphs();
  ui->canvas_V->replot();
  ui->canvas_V->rescaleAxes();

  ui->canvas_A->xAxis->setRange(0, 1);
  ui->canvas_A->yAxis->setRange(0, 1);

  ui->canvas_V->xAxis->setRange(0, 1);
  ui->canvas_V->yAxis->setRange(0, 1);

  ui->lineEdit_current_buffer->clear();
  ui->lineEdit_samples_reserve->clear();
  ui->lineEdit_RMS_T->clear();
  ui->lineEdit_PWM_value->clear();

  ui->lineEdit_RMS_A_x->clear();
  ui->lineEdit_RMS_A_y->clear();
  ui->lineEdit_RMS_A_z->clear();
  ui->lineEdit_RMS_A_xyz->clear();

  ui->lineEdit_RMS_V_x->clear();
  ui->lineEdit_RMS_V_y->clear();
  ui->lineEdit_RMS_V_z->clear();
  ui->lineEdit_RMS_V_xyz->clear();

  ui->lineEdit_x_mg->clear();
  ui->lineEdit_y_mg->clear();
  ui->lineEdit_z_mg->clear();

  ui->canvas_A->update();
  ui->canvas_V->update();

  setupGraphsOnce(0, true);
  setupGraphsOnce(1, true);
}

void MainWindow::slotClearConsole() { ui->UART_output->clear(); }

void MainWindow::slotClearConfig()
{
  ui->lineEdit_DL_value->setValue(0);
  ui->lineEdit_UL_value->setValue(0);
  ui->cmb_measuring_parameter->setCurrentIndex(-1);
  ui->cmb_axis_measuring->setCurrentIndex(-1);
  ui->lineEdit_mmpersec_value->setText("");
  ui->cmb_dynamic_ranges->setCurrentIndex(-1);
  ui->lineEdit_thermointercept->setText("");
  ui->lineEdit_thermoslope->setText("");
  ui->lineEdit_thermo_lowTemperature_constant->setText("");
  ui->lineEdit_constant_value->setText("");
  ui->cmb_constant_component->setCurrentIndex(-1);
  ui->cmb_axis->setCurrentIndex(-1);
  ui->lineEdit_integration_beta->setText("");
  ui->lineEdit_reference_value->setText("");
  ui->lineEdit_ratio_transform->setText("");
}

void MainWindow::slotClearAll()
{
  slotClearConfig();
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
  if (file.open(QIODevice::ReadOnly | QIODevice::Text))
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

  foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts())
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
      if (ui->comboBox_port->currentIndex() == i && buttonState == COM_PORT_CONNECTED)
      {
        on_pushButton_COM_connect_clicked();
      }
      ui->comboBox_port->removeItem(i);
    }
  }

  // Добавление новых COM-портов в комбобокс
  foreach (const QString& portName, availablePorts)
  {
    if (ui->comboBox_port->findText(portName) == -1) // Проверка наличия порта в комбобоксе
    {
      ui->comboBox_port->addItem(portName);
    }
  }

  for (int i = 0; i < ui->comboBox_port->count(); ++i)
  {
    QString itemText = ui->comboBox_port->itemText(i);
    if (itemText.contains(text1, Qt::CaseInsensitive) || itemText.contains(text2, Qt::CaseInsensitive) || itemText.contains(text3, Qt::CaseInsensitive))
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
  messageCode_ = settingsQt.value("messageCode", "\n").toString();
  dataBits_ = static_cast<QSerialPort::DataBits>(settingsQt.value("dataBits", 8).toInt());

  QString tempParity = settingsQt.value("parityControl", "Не используется").toString();
  if (tempParity == "Не используется")
    parityControl_ = QSerialPort::NoParity;
  else if (tempParity == "Четность")
    parityControl_ = QSerialPort::EvenParity;
  else if (tempParity == "Нечетность")
    parityControl_ = QSerialPort::OddParity;
  else if (tempParity == "Пространственный")
    parityControl_ = QSerialPort::SpaceParity;
  else if (tempParity == "Маркировочный")
    parityControl_ = QSerialPort::MarkParity;

  QString tempStopBits = settingsQt.value("stopBits", "1").toString();
  if (tempStopBits == "1")
    stopBits_ = QSerialPort::OneStop;
  else if (tempStopBits == "1.5")
    stopBits_ = QSerialPort::OneAndHalfStop;
  else if (tempStopBits == "2")
    stopBits_ = QSerialPort::TwoStop;

  QString tempFlowControl = settingsQt.value("flowControl", "Не используется").toString();
  if (tempFlowControl == "Не используется")
    flowControl_ = QSerialPort::NoFlowControl;
  else if (tempFlowControl == "Аппаратный")
    flowControl_ = QSerialPort::HardwareControl;
  else if (tempFlowControl == "Программный")
    flowControl_ = QSerialPort::SoftwareControl;

  settingsQt.endGroup();

  tempStruct.baudRate = QString::number(baudRate_);
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
  menuClear->addAction(tr("Очистить конфигурацию"), this, SLOT(slotClearConfig()));
  menuClear->addAction(tr("Очистить консоль"), this, SLOT(slotClearConsole()));
  menuClear->addAction(tr("Очистить данные"), this, SLOT(slotClearCanvas()));
  menuClear->addAction(tr("Очистить всё"), this, SLOT(slotClearAll()));
  ui->menuClear->setMenu(menuClear);
}

void MainWindow::initializeConnects()
{
  /* Коннекты связей между плоттером графиков и GUI */
  connect(ui->canvas_A, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(slotMouseMove(QMouseEvent*)));
  connect(ui->canvas_A, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(slotMouseDoubleClick(QMouseEvent*)));
  connect(ui->canvas_A, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(slotMousePress(QMouseEvent*)));
  connect(ui->canvas_A, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(slotMouseRelease(QMouseEvent*)));

  /* Коннекты связей между плоттером графиков и GUI */
  connect(ui->canvas_V, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(slotMouseMove(QMouseEvent*)));
  connect(ui->canvas_V, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(slotMouseDoubleClick(QMouseEvent*)));
  connect(ui->canvas_V, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(slotMousePress(QMouseEvent*)));
  connect(ui->canvas_V, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(slotMouseRelease(QMouseEvent*)));

  connect(&settingsUI_, SIGNAL(needSaveSettings(appSettingsStruct)), this, SLOT(saveAppSettings(appSettingsStruct)));
  connect(this, SIGNAL(setSettingsUI(appSettingsStruct)), &settingsUI_, SLOT(setVisibleSettings(appSettingsStruct)));

  connect(&serialTimer, SIGNAL(timeout()), this, SLOT(serialPortCheckout()));
}


void MainWindow::setupCommandMappings()
{
    QList<CommandMapping> mappings =
    {
        {ui->pushButton_get_config, nullptr, CMD_GET_CONFIG},
        {ui->pushButton_dynamic_range_write, ui->cmb_dynamic_ranges, CMD_DYNAMIC_MODE_SET},
        {ui->pushButton_DL_write, ui->lineEdit_DL_value, CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION},
        {ui->pushButton_UL_write, ui->lineEdit_UL_value, CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION},
        {ui->pushButton_mmpersec_write, ui->lineEdit_mmpersec_value, CMD_MAX_PARAMETER_VALUE_SET},
        {ui->pushButton_thermoslope_write, ui->lineEdit_thermoslope, CMD_THERMOSLOPE_SET},
        {ui->pushButton_thermointercept_write, ui->lineEdit_thermointercept, CMD_THERMOINTERCEPT_SET},
        {ui->pushButton_thermo_lowTemperature_constant_write, ui->lineEdit_thermo_lowTemperature_constant, CMD_THERMO_LOWTEMPERATURE_CONSTANT_SET},
        {ui->pushButton_constant_value_write, ui->lineEdit_constant_value, CMD_CONSTANT_VALUE_SET},
        {ui->pushButton_axis_write, ui->cmb_axis, CMD_CALIBRATE_DEVICE},
        {ui->pushButton_measuring_axis_write, ui->cmb_axis_measuring, CMD_CHANGE_MEASURING_AXIS_SET},
        {ui->pushButton_constant_component_write, ui->cmb_constant_component, CMD_REMOVE_CONSTANT_COMPONENT_SET},
        {ui->pushButton_measuring_parameter_write, ui->cmb_measuring_parameter, CMD_CHANGE_MEASURING_PARAMETER_SET},
        {ui->pushButton_integration_beta_write, ui->lineEdit_integration_beta, CMD_SET_INTEGRATION_BETA},
        {ui->pushButton_reference_value_write, ui->lineEdit_reference_value, CMD_SET_REFERENCE_VALUE},
        {ui->pushButton_ratio_transform_write, ui->lineEdit_ratio_transform, CMD_SET_RATIO_TRANSFORM}
    };

    for (const auto& mapping : mappings)
    {
        connect(mapping.button, &QPushButton::clicked, this, [this, mapping]()
        {
            handleCommand(mapping);
        });
    }
}

void MainWindow::handleCommand(const CommandMapping& mapping)
{
    if (!mapping.widget)
    {
        // Если виджет не используется, просто отправляем команду
        writeToSerial(mapping.command);
    }
    else if (QLineEdit* lineEdit = qobject_cast<QLineEdit*>(mapping.widget))
    {
        // Если виджет это QLineEdit
        sendCommand(mapping.command, lineEdit);
    }
    else if (QComboBox* comboBox = qobject_cast<QComboBox*>(mapping.widget))
    {
        // Если виджет это QComboBox
        sendCommand(mapping.command, comboBox);
    }
    else if (QSpinBox* spinBox = qobject_cast<QSpinBox*>(mapping.widget))
    {
        // Если виджет это QSpinBox
        sendCommand(mapping.command, spinBox);
    }
}

void MainWindow::on_pushButton_thermohelp_clicked()
{
    thermoHelp.setReadOnly(true);
    QString htmlString = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                         "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
                         "p, li { white-space: pre-wrap; }\n"
                         "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
                         "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">При температуре от "
                         "-50 до +10 °C формула:</span></p>\n"
                         "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">        </span><span "
                         "style=\" font-size:10pt; font-weight:600;\">ШИМ</span><span style=\" font-size:10pt; font-weight:600; vertical-align:sub;\">выход</span><span style=\" font-size:10pt;\"> = "
                         "наклон • температура + смещение + ШИМ</span><span style=\" font-size:10pt; vertical-align:sub;\">расчетный</span></p>\n"
                         "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; "
                         "vertical-align:sub;\"><br /></p>\n"
                         "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">При температуре от "
                         "-50 °C и ниже:<br />        </span><span style=\" font-size:10pt; font-weight:600;\">ШИМ</span><span style=\" font-size:10pt; font-weight:600; "
                         "vertical-align:sub;\">выход</span><span style=\" font-size:10pt;\"> = константа + ШИМ</span><span style=\" font-size:10pt; vertical-align:sub;\">расчетный</span></p>\n"
                         "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; "
                         "vertical-align:sub;\"><br /></p>\n"
                         "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">При температуре от "
                         "+10 °C и выше:</span></p>\n"
                         "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">        </span><span "
                         "style=\" font-size:10pt; font-weight:600;\">ШИМ</span><span style=\" font-size:10pt; font-weight:600; vertical-align:sub;\">выход</span><span style=\" font-size:10pt;\"> = "
                         "ШИМ</span><span style=\" font-size:10pt; vertical-align:sub;\">расчетный</span></p></body></html>";
    thermoHelp.setFixedWidth(420);
    thermoHelp.setFixedHeight(160);
    thermoHelp.setHtml(htmlString);
    thermoHelp.show();
}
