#include <mainwindow.h>
#include <ui_mainwindow.h>

// Вспомогательная функция для отправки данных через последовательный порт
void MainWindow::writeToSerial(const char* command)
{
    if (serialPort && serialPort->isOpen())
    {
        serialPort->write(command);
    }
    else
    {
        printConsole("[ERROR]: Последовательный порт не открыт");
    }
}

// Обработчик нажатия кнопки для пользовательских команд
void MainWindow::on_pushButton_userCommand_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Пользовательская команда",
                                         "Введите команду:", QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty())
    {
        writeToSerial(text.toUtf8().constData());
    }
}

// Обработчик для отправки параметризированных команд с использованием QLineEdit
void MainWindow::sendCommand(const char* commandBase, QLineEdit* lineEdit)
{
    if (lineEdit && !lineEdit->text().isEmpty())
    {
        QString fullCommand = QString(commandBase) + lineEdit->text();
        writeToSerial(fullCommand.toUtf8().constData());
    }
}

// Обработчики для команд, задаваемых через QComboBox
void MainWindow::sendCommand(const char* commandBase, QComboBox* comboBox)
{
    if (comboBox)
    {
        QString fullCommand = QString(commandBase) + QString::number(comboBox->currentIndex());
        writeToSerial(fullCommand.toUtf8().constData());
    }
}

// Обработчики для команд, задаваемых через QSpinBox
void MainWindow::sendCommand(const char* commandBase, QSpinBox* spinBox)
{
    if (spinBox)
    {
        QString fullCommand = QString(commandBase) + QString::number(spinBox->value());
        writeToSerial(fullCommand.toUtf8().constData());
    }
}

// Обработчик нажатия кнопки для установки настроек по умолчанию
void MainWindow::on_pushButton_default_settings_set_clicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Сброс изделия до заводских настроек");

    QFormLayout form(&dialog);

    QLabel *label = new QLabel(&dialog);
    QLabel *labelSure = new QLabel(&dialog);
    label->setText("Применение этой команды сбросит все настройки изделия до заводского состояния.\n");
    labelSure->setText("Вы уверены?\n");
    labelSure->setAlignment(Qt::AlignCenter);
    form.addRow(label);
    form.addRow(labelSure);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);

    buttonBox.button(QDialogButtonBox::Ok)->setText("Сбросить");
    buttonBox.button(QDialogButtonBox::Cancel)->setText("Отмена");
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted)
    {
        writeToSerial(CMD_DEFAULT_SETTINGS_SET);
    }
}

void MainWindow::on_pushButton_get_config_clicked()
{
    writeToSerial(CMD_GET_CONFIG);
}

void MainWindow::on_pushButton_dynamic_range_write_clicked()
{
    sendCommand(CMD_DYNAMIC_MODE_SET, ui->cmb_dynamic_ranges);
}

// Обработчики для различных параметризированных команд
void MainWindow::on_pushButton_DL_write_clicked()
{
    sendCommand(CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION, ui->lineEdit_DL_value);
}

void MainWindow::on_pushButton_UL_write_clicked()
{
    sendCommand(CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION, ui->lineEdit_UL_value);
}

void MainWindow::on_pushButton_mmpersec_write_clicked()
{
    sendCommand(CMD_MAX_PARAMETER_VALUE_SET, ui->lineEdit_mmpersec_value);
}

void MainWindow::on_pushButton_thermoslope_write_clicked()
{
    sendCommand(CMD_THERMOSLOPE_SET, ui->lineEdit_thermoslope);
}

void MainWindow::on_pushButton_thermointercept_write_clicked()
{
    sendCommand(CMD_THERMOINTERCEPT_SET, ui->lineEdit_thermointercept);
}

void MainWindow::on_pushButton_thermo_lowTemperature_constant_write_clicked()
{
    sendCommand(CMD_THERMO_LOWTEMPERATURE_CONSTANT_SET, ui->lineEdit_thermo_lowTemperature_constant);
}

void MainWindow::on_pushButton_constant_value_write_clicked()
{
    sendCommand(CMD_CONSTANT_VALUE_SET, ui->lineEdit_constant_value);
}

void MainWindow::on_pushButton_axis_write_clicked()
{
    sendCommand(CMD_CALIBRATE_DEVICE, ui->cmb_axis);
}

void MainWindow::on_pushButton_measuring_axis_write_clicked()
{
    sendCommand(CMD_CHANGE_MEASURING_AXIS_SET, ui->cmb_axis_measuring);
}

void MainWindow::on_pushButton_constant_component_write_clicked()
{
    sendCommand(CMD_REMOVE_CONSTANT_COMPONENT_SET, ui->cmb_constant_component);
}

void MainWindow::on_pushButton_measuring_parameter_write_clicked()
{
    sendCommand(CMD_CHANGE_MEASURING_PARAMETER_SET, ui->cmb_measuring_parameter);
}
