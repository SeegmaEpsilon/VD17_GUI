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
  QString text = QInputDialog::getText(this, "Пользовательская команда", "Введите команду:", QLineEdit::Normal, "", &ok);
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

  QLabel* label = new QLabel(&dialog);
  QLabel* labelSure = new QLabel(&dialog);
  label->setText("Применение этой команды сбросит все настройки изделия до заводского состояния.\n");
  labelSure->setText("Вы уверены?\n");
  labelSure->setAlignment(Qt::AlignCenter);
  form.addRow(label);
  form.addRow(labelSure);

  QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);

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

void MainWindow::on_pushButton_start_configure_clicked()
{
  QString fullCommand = QString(PASSWORD_CONFIG);
  writeToSerial(fullCommand.toUtf8().constData());
}

