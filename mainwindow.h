#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qserialport.h>
#include <qserialportinfo.h>
#include <QTimer>
#include <QTextCodec>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QApplication>
#include <QTextCodec>
#include <QElapsedTimer>
#include <qcustomplot.h>
#include <QFileDialog>
#include <QFile>
#include <QMenu>
#include <QSettings>
#include <appsettings.h>

#include <support.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void setSettingsUI(appSettingsStruct settings);

private slots:
    void printConsole(const QString& string);

    void on_pushButton_DL_calibration_clicked();

    void disable_all_widgets();

    void enable_all_widgets();

    void reset_all_widgets();

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

    void plotGraph(QString& msg);

    void on_pushButton_dynamic_range_set_clicked();

    void on_pushButton_dynamic_range_write_clicked();

    void on_pushButton_clear_canvas_clicked();

    void on_pushButton_clear_console_clicked();

    void on_pushButton_manual_clicked();

    bool serialPortCheckout();

    void slotMouseMove(QMouseEvent * event);
    void slotMouseDoubleClick(QMouseEvent * event);
    void slotMousePress(QMouseEvent* event);
    void slotMouseRelease(QMouseEvent* event);

    void slotSavePlotPNG();
    void slotResetCanvas();
    void slotSaveDataFromPlot();

    void on_pushButton_settings_clicked();

    void initializeAppSettings();
    void saveAppSettings(appSettingsStruct tempSettings);

    void on_pushButton_userCommand_clicked();

  private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
    QSerialPortInfo info;

    QString serialBuffer;

    CircularBuffer cbA;
    CircularBuffer cbV;

    uint32_t counter;

    double valueA;
    double valueV;

    uint8_t flagMeasureDone;
    uint8_t buttonState;

    QTimer serialTimer;

    QTime time_;
    QCPRange DragStartHorzRange_;
    QCPRange DragStartVertRange_;
    QPoint mDragStart_;
    bool isMouseHold_;
    QElapsedTimer mouseHoldTimer_;

    appSettings settingsUI_;

    /* Необходимые настройки для COM-порта */
    int bufferSize_;
    QString messageCode_;

    int baudRate_;
    int dataBits_;
    int parityControl_;
    int stopBits_;
    int flowControl_;
};

#endif // MAINWINDOW_H
