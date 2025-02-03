#ifndef SUPPORT_H
#define SUPPORT_H

#include <QDebug>
#include <QString>
#include <vector>
#include <QPushButton>

#define PASSWORD_CONFIG "FalloutNewVegasStalkerGammaTerrariaFactorio"
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
#define CMD_SET_INTEGRATION_BETA "IB"
#define CMD_SET_REFERENCE_VALUE "RV"
#define CMD_SET_RATIO_TRANSFORM "RT"

#define SOFTWARE_VERSION QString("2.8.2")

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
  QString baudRate;
  QString dataBits;
  QString parityControl;
  QString stopBits;
  QString flowControl;
};

struct CommandMapping
{
    QPushButton* button;
    QWidget* widget;  // QLineEdit, QComboBox или QSpinBox
    const char* command;
};

#endif // SUPPORT_H
