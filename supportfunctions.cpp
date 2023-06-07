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
