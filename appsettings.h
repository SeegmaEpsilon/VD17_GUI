#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QDialog>
#include <support.h>
#include <QSerialPort>
#include <QPushButton>

namespace Ui {
  class appSettings;
}

class appSettings : public QDialog
{
    Q_OBJECT

  public:
    explicit appSettings(QWidget *parent = 0);
    ~appSettings();

  private:
    Ui::appSettings *ui;

  signals:
    void needSaveSettings(appSettingsStruct settings);

  private slots:
    void on_buttonBox_accepted();
    void setVisibleSettings(appSettingsStruct settings);
    void on_pushButton_defaultSettings_clicked();
};

#endif // APPSETTINGS_H
