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

void MainWindow::on_pushButton_DL_multimeter_clicked()
{
    QString str_temp = ui->lineEdit_DL_value->text();

    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
}

void MainWindow::on_pushButton_DL_write_clicked()
{
    serialPort->write(CMD_DOWN_LIMIT_CURRENT_LOOP_WRITE);
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
    serialPort->write(CMD_UP_LIMIT_CURRENT_LOOP_WRITE);
    reset_all_widgets();
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
    reset_all_widgets();
}


void MainWindow::on_pushButton_thermoslope_write_clicked()
{
    QString str_temp = ui->lineEdit_thermoslope->text();

    const char* pcData = str_temp.toStdString().c_str();
    serialPort->write(pcData);
    reset_all_widgets();
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
    const char* pcData = ui->cmb_dynamic_ranges->currentText().toStdString().c_str();
    serialPort->write(pcData);
    reset_all_widgets();
}

void MainWindow::on_pushButton_calibrate_device_clicked()
{
    serialPort->write(CMD_CALIBRATE_DEVICE);
}
