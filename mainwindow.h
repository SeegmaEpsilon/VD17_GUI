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
    void slotTimerTimeout();

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

    void on_comboBox_port_highlighted(const int &index);

    void on_pushButton_manual_clicked();

  private:
    Ui::MainWindow *ui;
    QSerialPort serialPort;
    QSerialPortInfo info;

    QString serialBuffer;

    double valueA;
    double valueV;

    QVector<double> averageBufferA;
    QVector<double> averageBufferV;

    unsigned counter;

    QTimer timer;

    unsigned int flagMeasureDone;

    int highlightedIndex;
};



#endif // MAINWINDOW_H
