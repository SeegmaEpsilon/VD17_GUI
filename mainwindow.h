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

#define CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION "DL" // calibration of down limit current loop (4mA)
#define CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION "UL"   // calibration of up limit current loop (20mA)
#define CMD_DYNAMIC_MODE_SET "DR"                    // setting dynamic range of accelerometer
#define CMD_MM_PER_SEC_SET "MV"                      // setting max mm/s of device
#define CMD_CALIBRATE_DEVICE "CD"                    // calibrate the device (10.1 m/s^2)

#define CMD_DOWN_LIMIT_CURRENT_LOOP_WRITE "DLWW"
#define CMD_UP_LIMIT_CURRENT_LOOP_WRITE "ULWW"
#define CMD_MM_PER_SEC_WRITE "MMW"
#define CMD_DYNAMIC_MODE_WRITE "MW"
#define CMD_FLASH_WRITE "WS"

#define MS_DATA_TIMEOUT 5000
#define MS_SERIAL_TIMEOUT 2500

enum BUTTON_STATE
{
    COM_PORT_DISCONNECTED = 0,
    COM_PORT_CONNECTED = 1
};

class CircularBuffer {
public:
    explicit CircularBuffer(int size) : size_(size), buffer_(size), head_(0), tail_(0), count_(0) {}

    void push(double value) {
        buffer_[head_] = value;
        head_ = (head_ + 1) % size_;
        if (head_ == tail_) {
            tail_ = (tail_ + 1) % size_;
        } else {
            count_ = std::min(count_ + 1, size_);
        }
    }

    double at(int index) const {
        if (index >= 0 && index < count_) {
            int bufferIndex = (tail_ + index) % size_;
            return buffer_[bufferIndex];
        }
        return 0;
    }

    double average()
    {
      average_ = 0.0;
      for(int i = 0; i < count_; i++)
      {
        average_ += buffer_.at(i);
      }
      return average_/count_;
    }

    int size() const {
        return count_;
    }

private:
    int size_;
    std::vector<double> buffer_;
    int head_;
    int tail_;
    int count_;
    double average_;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
};

#endif // MAINWINDOW_H
