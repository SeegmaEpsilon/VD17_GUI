#ifndef SUPPORT_H
#define SUPPORT_H

#include <QString>
#include <vector>
#include <QDebug>

#define CMD_DOWN_LIMIT_CURRENT_LOOP_CALIBRATION "DL" // calibration of down limit current loop (4mA)
#define CMD_UP_LIMIT_CURRENT_LOOP_CALIBRATION "UL"   // calibration of up limit current loop (20mA)
#define CMD_DYNAMIC_MODE_SET "DR"                    // setting dynamic range of accelerometer
#define CMD_MAX_PARAMETER_VALUE_SET "MV"             // setting max mm/s of device
#define CMD_CALIBRATE_DEVICE "CD"                    // calibrate the device (10.1 m/s^2)
#define CMD_THERMOSLOPE_SET "TS"                     // settings thermoslope for device
#define CMD_THERMOINTERCEPT_SET "TI"                 // settings thermointercept for device
#define CMD_THERMO_LOWTEMPERATURE_CONSTANT_SET "LT"  // settings constant value at low temperature
#define CMD_CONSTANT_VALUE_SET "CV"                  // settings constant value for device
#define CMD_DEFAULT_SETTINGS_SET "DS"                // settings default settings
#define CMD_CHANGE_MEASURING_AXIS_SET "MA"
#define CMD_CHANGE_MEASURING_PARAMETER_SET "MP"
#define CMD_REMOVE_CONSTANT_COMPONENT_SET "CC"
#define CMD_GET_CONFIG "GC"

#define SOFTWARE_VERSION QString("2.7.1")

#define MS_DATA_TIMEOUT 5000
#define MS_SERIAL_TIMEOUT 2500

typedef enum
{
    COM_PORT_DISCONNECTED = 0,
    COM_PORT_CONNECTED = 1
} button_state_t;

typedef enum
{
    DRAW_ACCELERATION = 0,
    DRAW_VELOCITY = 1
} canvas_t;

struct appSettingsStruct
{
    void print()
    {
      qDebug() << "baud rate is " << baudRate;
      qDebug() << "data bits is" << dataBits;
      qDebug() << "parity control is " << parityControl;
      qDebug() << "stop bits is" << stopBits;
      qDebug() << "flow control is " << flowControl;
      qDebug() << "__________________________________";
    }

    QString baudRate;
    QString dataBits;
    QString parityControl;
    QString stopBits;
    QString flowControl;
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

    int resize(int size) {
        buffer_.resize(size);
        size_ = buffer_.size();
        return size_;
    }

private:
    int size_;
    std::vector<double> buffer_;
    int head_;
    int tail_;
    int count_;
    double average_;
};

#endif // SUPPORT_H
