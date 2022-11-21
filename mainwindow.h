#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void printConsole(QString string);

private slots:
    void keyPressEvent(QKeyEvent *event);

    void on_pushButton_DL_calibration_clicked();

    void disable_all_widgets();

    void on_pushButton_DL_write_clicked();

    void on_pushButton_DL_multimeter_clicked();

    void on_pushButton_UL_calibration_clicked();

    void on_pushButton_UL_multimeter_clicked();

    void on_pushButton_UL_write_clicked();

    void on_pushButton_mmpersec_calibration_clicked();

    void on_pushButton_mmpersec_write_clicked();

    void on_pushButton_calibrate_device_clicked();

    void on_pushButton_COM_connect_clicked();

    void receiveMessage();

    void plotGraph(QString msg);

    void on_comboBox_port_activated(const QString &arg1);

    void on_pushButton_dynamic_range_set_clicked();

    void on_pushButton_dynamic_range_write_clicked();

    void on_pushButton_clear_canvas_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
    QSerialPortInfo info;

    QByteArray serialData;
    QString serialBuffer;
    QStringList serialList;

    QVector<double> X_Axis;
    QVector<double> Y_Axis;
    unsigned counter;
};



#endif // MAINWINDOW_H
