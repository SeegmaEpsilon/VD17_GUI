#include <mainwindow.h>
#include <ui_mainwindow.h>


// TODO реализовать пользовательские команды
void MainWindow::on_pushButton_userCommand_clicked()
{
    bool ok;
    // Ask for birth date as a string.
    QString text = QInputDialog::getText(this, "Пользовательская команда",
                                         "Введите команду:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
    {
        QString uiNotification = "Отправлена команда ";
        uiNotification += text;
        serialPort->write(text.toStdString().c_str());
        printConsole(uiNotification);
    }
}

void MainWindow::on_pushButton_DL_calibration_clicked()
{
    disable_all_widgets();
    ui->lineEdit_DL_value->setEnabled(true);
    ui->pushButton_DL_multimeter->setEnabled(true);
    ui->pushButton_DL_write->setEnabled(true);

    serialPort->write(CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION);
}


void MainWindow::on_pushButton_thermoslope_set_clicked()
{
    disable_all_widgets();
    ui->lineEdit_thermoslope->setEnabled(true);
    ui->pushButton_thermoslope_write->setEnabled(true);

    serialPort->write(CMD_THERMOSLOPE_SET);
}

void MainWindow::on_pushButton_thermointercept_set_clicked()
{
    disable_all_widgets();
    ui->lineEdit_thermointercept->setEnabled(true);
    ui->pushButton_thermointercept_write->setEnabled(true);

    serialPort->write(CMD_THERMOINTERCEPT_SET);
}

void MainWindow::on_pushButton_thermo_lowTemperature_constant_set_clicked()
{
    disable_all_widgets();
    ui->lineEdit_thermo_lowTemperature_constant->setEnabled(true);
    ui->pushButton_thermo_lowTemperature_constant_write->setEnabled(true);

    serialPort->write(CMD_THERMO_LOWTEMPERATURE_CONSTANT_SET);
}

void MainWindow::on_pushButton_constant_value_set_clicked()
{
    disable_all_widgets();
    ui->lineEdit_constant_value->setEnabled(true);
    ui->pushButton_constant_value_write->setEnabled(true);

    serialPort->write(CMD_CONSTANT_VALUE_SET);
}

void MainWindow::on_pushButton_default_settings_set_clicked()
{
    disable_all_widgets();
    serialPort->write(CMD_DEFAULT_SETTINGS_SET);
}

void MainWindow::on_pushButton_DL_multimeter_clicked()
{
    QString str_temp = ui->lineEdit_DL_value->text();

    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
}

void MainWindow::on_pushButton_DL_write_clicked()
{
    serialPort->write(CMD_CURRENT_LOOP_WRITE);
    reset_all_widgets();
}

void MainWindow::on_pushButton_UL_calibration_clicked()
{
    disable_all_widgets();
    ui->lineEdit_UL_value->setEnabled(true);
    ui->pushButton_UL_multimeter->setEnabled(true);
    ui->pushButton_UL_write->setEnabled(true);

    serialPort->write(CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION);
}

void MainWindow::on_pushButton_UL_multimeter_clicked()
{
    QString str_temp = ui->lineEdit_UL_value->text();
    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
}

void MainWindow::on_pushButton_UL_write_clicked()
{
    serialPort->write(CMD_CURRENT_LOOP_WRITE);
    disable_all_widgets();
}

void MainWindow::on_pushButton_mmpersec_calibration_clicked()
{
    disable_all_widgets();
    ui->lineEdit_mmpersec_value->setEnabled(true);
    ui->pushButton_mmpersec_write->setEnabled(true);

    serialPort->write(CMD_MM_PER_SEC_SET);
}

void MainWindow::on_pushButton_mmpersec_write_clicked()
{
    QString str_temp = ui->lineEdit_mmpersec_value->text();
    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
    disable_all_widgets();
}


void MainWindow::on_pushButton_thermoslope_write_clicked()
{
    QString str_temp = ui->lineEdit_thermoslope->text();

    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
    disable_all_widgets();
}

void MainWindow::on_pushButton_thermointercept_write_clicked()
{
    QString str_temp = ui->lineEdit_thermointercept->text();

    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
    disable_all_widgets();
}

void MainWindow::on_pushButton_thermo_lowTemperature_constant_write_clicked()
{
    QString str_temp = ui->lineEdit_thermo_lowTemperature_constant->text();

    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
    disable_all_widgets();
}

void MainWindow::on_pushButton_constant_value_write_clicked()
{
    QString str_temp = ui->lineEdit_constant_value->text();

    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
    disable_all_widgets();
}

void MainWindow::on_pushButton_dynamic_range_set_clicked()
{
    disable_all_widgets();
    ui->cmb_dynamic_ranges->setEnabled(true);
    ui->pushButton_dynamic_range_write->setEnabled(true);

    serialPort->write(CMD_DYNAMIC_MODE_SET);
}

void MainWindow::on_pushButton_dynamic_range_write_clicked()
{
    QMap<QString, QString> map;
    map["2g"] = "0";
    map["4g"] = "1";
    map["8g"] = "2";
    map["16g"] = "3";

    QString dynamicRange = map[ui->cmb_dynamic_ranges->currentText()];

    const char* pcData = dynamicRange.toStdString().c_str();
    serialPort->write(pcData);
    disable_all_widgets();
}

void MainWindow::on_pushButton_calibrate_device_clicked()
{
    disable_all_widgets();
    ui->cmb_axis->setEnabled(true);
    ui->pushButton_axis_write->setEnabled(true);

    serialPort->write(CMD_CALIBRATE_DEVICE);
}

void MainWindow::on_pushButton_axis_write_clicked()
{
  QString currentAxis = QString::number(ui->cmb_axis->currentIndex());

  const char* pcData = currentAxis.toStdString().c_str();
  serialPort->write(pcData);
}
