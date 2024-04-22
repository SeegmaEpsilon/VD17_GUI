/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[72];
    char stringdata0[1708];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "setSettingsUI"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "appSettingsStruct"
QT_MOC_LITERAL(4, 44, 8), // "settings"
QT_MOC_LITERAL(5, 53, 12), // "printConsole"
QT_MOC_LITERAL(6, 66, 6), // "string"
QT_MOC_LITERAL(7, 73, 36), // "on_pushButton_DL_calibration_..."
QT_MOC_LITERAL(8, 110, 19), // "disable_all_widgets"
QT_MOC_LITERAL(9, 130, 17), // "reset_all_widgets"
QT_MOC_LITERAL(10, 148, 30), // "on_pushButton_DL_write_clicked"
QT_MOC_LITERAL(11, 179, 35), // "on_pushButton_DL_multimeter_c..."
QT_MOC_LITERAL(12, 215, 36), // "on_pushButton_UL_calibration_..."
QT_MOC_LITERAL(13, 252, 35), // "on_pushButton_UL_multimeter_c..."
QT_MOC_LITERAL(14, 288, 30), // "on_pushButton_UL_write_clicked"
QT_MOC_LITERAL(15, 319, 42), // "on_pushButton_mmpersec_calibr..."
QT_MOC_LITERAL(16, 362, 36), // "on_pushButton_mmpersec_write_..."
QT_MOC_LITERAL(17, 399, 38), // "on_pushButton_calibrate_devic..."
QT_MOC_LITERAL(18, 438, 33), // "on_pushButton_COM_connect_cli..."
QT_MOC_LITERAL(19, 472, 14), // "receiveMessage"
QT_MOC_LITERAL(20, 487, 9), // "plotGraph"
QT_MOC_LITERAL(21, 497, 8), // "QString&"
QT_MOC_LITERAL(22, 506, 3), // "msg"
QT_MOC_LITERAL(23, 510, 39), // "on_pushButton_dynamic_range_s..."
QT_MOC_LITERAL(24, 550, 41), // "on_pushButton_dynamic_range_w..."
QT_MOC_LITERAL(25, 592, 28), // "on_pushButton_manual_clicked"
QT_MOC_LITERAL(26, 621, 18), // "serialPortCheckout"
QT_MOC_LITERAL(27, 640, 13), // "slotMouseMove"
QT_MOC_LITERAL(28, 654, 12), // "QMouseEvent*"
QT_MOC_LITERAL(29, 667, 5), // "event"
QT_MOC_LITERAL(30, 673, 20), // "slotMouseDoubleClick"
QT_MOC_LITERAL(31, 694, 14), // "slotMousePress"
QT_MOC_LITERAL(32, 709, 16), // "slotMouseRelease"
QT_MOC_LITERAL(33, 726, 15), // "slotSavePlotPNG"
QT_MOC_LITERAL(34, 742, 15), // "slotResetCanvas"
QT_MOC_LITERAL(35, 758, 20), // "slotSaveDataFromPlot"
QT_MOC_LITERAL(36, 779, 30), // "on_pushButton_settings_clicked"
QT_MOC_LITERAL(37, 810, 18), // "initializeConnects"
QT_MOC_LITERAL(38, 829, 21), // "initializeAppSettings"
QT_MOC_LITERAL(39, 851, 14), // "initializeMenu"
QT_MOC_LITERAL(40, 866, 16), // "initializeCanvas"
QT_MOC_LITERAL(41, 883, 15), // "saveAppSettings"
QT_MOC_LITERAL(42, 899, 12), // "tempSettings"
QT_MOC_LITERAL(43, 912, 33), // "on_pushButton_userCommand_cli..."
QT_MOC_LITERAL(44, 946, 15), // "serialGetConfig"
QT_MOC_LITERAL(45, 962, 15), // "slotClearCanvas"
QT_MOC_LITERAL(46, 978, 16), // "slotClearConsole"
QT_MOC_LITERAL(47, 995, 12), // "slotClearAll"
QT_MOC_LITERAL(48, 1008, 37), // "on_pushButton_thermoslope_set..."
QT_MOC_LITERAL(49, 1046, 39), // "on_pushButton_thermoslope_wri..."
QT_MOC_LITERAL(50, 1086, 40), // "on_pushButton_constant_value_..."
QT_MOC_LITERAL(51, 1127, 41), // "on_pushButton_thermointercept..."
QT_MOC_LITERAL(52, 1169, 43), // "on_pushButton_thermointercept..."
QT_MOC_LITERAL(53, 1213, 42), // "on_pushButton_constant_value_..."
QT_MOC_LITERAL(54, 1256, 42), // "on_pushButton_default_setting..."
QT_MOC_LITERAL(55, 1299, 56), // "on_pushButton_thermo_lowTempe..."
QT_MOC_LITERAL(56, 1356, 58), // "on_pushButton_thermo_lowTempe..."
QT_MOC_LITERAL(57, 1415, 32), // "on_pushButton_thermohelp_clicked"
QT_MOC_LITERAL(58, 1448, 19), // "updateComboBoxValue"
QT_MOC_LITERAL(59, 1468, 10), // "QComboBox*"
QT_MOC_LITERAL(60, 1479, 8), // "comboBox"
QT_MOC_LITERAL(61, 1488, 7), // "message"
QT_MOC_LITERAL(62, 1496, 19), // "updateLineEditValue"
QT_MOC_LITERAL(63, 1516, 10), // "QLineEdit*"
QT_MOC_LITERAL(64, 1527, 8), // "lineEdit"
QT_MOC_LITERAL(65, 1536, 17), // "handleInitMessage"
QT_MOC_LITERAL(66, 1554, 18), // "updateSpinBoxValue"
QT_MOC_LITERAL(67, 1573, 9), // "QSpinBox*"
QT_MOC_LITERAL(68, 1583, 7), // "spinBox"
QT_MOC_LITERAL(69, 1591, 32), // "on_pushButton_axis_write_clicked"
QT_MOC_LITERAL(70, 1624, 40), // "on_pushButton_measuring_axis_..."
QT_MOC_LITERAL(71, 1665, 42) // "on_pushButton_measuring_axis_..."

    },
    "MainWindow\0setSettingsUI\0\0appSettingsStruct\0"
    "settings\0printConsole\0string\0"
    "on_pushButton_DL_calibration_clicked\0"
    "disable_all_widgets\0reset_all_widgets\0"
    "on_pushButton_DL_write_clicked\0"
    "on_pushButton_DL_multimeter_clicked\0"
    "on_pushButton_UL_calibration_clicked\0"
    "on_pushButton_UL_multimeter_clicked\0"
    "on_pushButton_UL_write_clicked\0"
    "on_pushButton_mmpersec_calibration_clicked\0"
    "on_pushButton_mmpersec_write_clicked\0"
    "on_pushButton_calibrate_device_clicked\0"
    "on_pushButton_COM_connect_clicked\0"
    "receiveMessage\0plotGraph\0QString&\0msg\0"
    "on_pushButton_dynamic_range_set_clicked\0"
    "on_pushButton_dynamic_range_write_clicked\0"
    "on_pushButton_manual_clicked\0"
    "serialPortCheckout\0slotMouseMove\0"
    "QMouseEvent*\0event\0slotMouseDoubleClick\0"
    "slotMousePress\0slotMouseRelease\0"
    "slotSavePlotPNG\0slotResetCanvas\0"
    "slotSaveDataFromPlot\0"
    "on_pushButton_settings_clicked\0"
    "initializeConnects\0initializeAppSettings\0"
    "initializeMenu\0initializeCanvas\0"
    "saveAppSettings\0tempSettings\0"
    "on_pushButton_userCommand_clicked\0"
    "serialGetConfig\0slotClearCanvas\0"
    "slotClearConsole\0slotClearAll\0"
    "on_pushButton_thermoslope_set_clicked\0"
    "on_pushButton_thermoslope_write_clicked\0"
    "on_pushButton_constant_value_set_clicked\0"
    "on_pushButton_thermointercept_set_clicked\0"
    "on_pushButton_thermointercept_write_clicked\0"
    "on_pushButton_constant_value_write_clicked\0"
    "on_pushButton_default_settings_set_clicked\0"
    "on_pushButton_thermo_lowTemperature_constant_set_clicked\0"
    "on_pushButton_thermo_lowTemperature_constant_write_clicked\0"
    "on_pushButton_thermohelp_clicked\0"
    "updateComboBoxValue\0QComboBox*\0comboBox\0"
    "message\0updateLineEditValue\0QLineEdit*\0"
    "lineEdit\0handleInitMessage\0"
    "updateSpinBoxValue\0QSpinBox*\0spinBox\0"
    "on_pushButton_axis_write_clicked\0"
    "on_pushButton_measuring_axis_set_clicked\0"
    "on_pushButton_measuring_axis_write_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  289,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  292,    2, 0x08 /* Private */,
       7,    0,  295,    2, 0x08 /* Private */,
       8,    0,  296,    2, 0x08 /* Private */,
       9,    0,  297,    2, 0x08 /* Private */,
      10,    0,  298,    2, 0x08 /* Private */,
      11,    0,  299,    2, 0x08 /* Private */,
      12,    0,  300,    2, 0x08 /* Private */,
      13,    0,  301,    2, 0x08 /* Private */,
      14,    0,  302,    2, 0x08 /* Private */,
      15,    0,  303,    2, 0x08 /* Private */,
      16,    0,  304,    2, 0x08 /* Private */,
      17,    0,  305,    2, 0x08 /* Private */,
      18,    0,  306,    2, 0x08 /* Private */,
      19,    0,  307,    2, 0x08 /* Private */,
      20,    1,  308,    2, 0x08 /* Private */,
      23,    0,  311,    2, 0x08 /* Private */,
      24,    0,  312,    2, 0x08 /* Private */,
      25,    0,  313,    2, 0x08 /* Private */,
      26,    0,  314,    2, 0x08 /* Private */,
      27,    1,  315,    2, 0x08 /* Private */,
      30,    1,  318,    2, 0x08 /* Private */,
      31,    1,  321,    2, 0x08 /* Private */,
      32,    1,  324,    2, 0x08 /* Private */,
      33,    0,  327,    2, 0x08 /* Private */,
      34,    0,  328,    2, 0x08 /* Private */,
      35,    0,  329,    2, 0x08 /* Private */,
      36,    0,  330,    2, 0x08 /* Private */,
      37,    0,  331,    2, 0x08 /* Private */,
      38,    0,  332,    2, 0x08 /* Private */,
      39,    0,  333,    2, 0x08 /* Private */,
      40,    0,  334,    2, 0x08 /* Private */,
      41,    1,  335,    2, 0x08 /* Private */,
      43,    0,  338,    2, 0x08 /* Private */,
      44,    0,  339,    2, 0x08 /* Private */,
      45,    0,  340,    2, 0x08 /* Private */,
      46,    0,  341,    2, 0x08 /* Private */,
      47,    0,  342,    2, 0x08 /* Private */,
      48,    0,  343,    2, 0x08 /* Private */,
      49,    0,  344,    2, 0x08 /* Private */,
      50,    0,  345,    2, 0x08 /* Private */,
      51,    0,  346,    2, 0x08 /* Private */,
      52,    0,  347,    2, 0x08 /* Private */,
      53,    0,  348,    2, 0x08 /* Private */,
      54,    0,  349,    2, 0x08 /* Private */,
      55,    0,  350,    2, 0x08 /* Private */,
      56,    0,  351,    2, 0x08 /* Private */,
      57,    0,  352,    2, 0x08 /* Private */,
      58,    2,  353,    2, 0x08 /* Private */,
      62,    2,  358,    2, 0x08 /* Private */,
      65,    1,  363,    2, 0x08 /* Private */,
      66,    2,  366,    2, 0x08 /* Private */,
      69,    0,  371,    2, 0x08 /* Private */,
      70,    0,  372,    2, 0x08 /* Private */,
      71,    0,  373,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 59, QMetaType::QString,   60,   61,
    QMetaType::Void, 0x80000000 | 63, QMetaType::QString,   64,   61,
    QMetaType::Void, QMetaType::QString,   61,
    QMetaType::Void, 0x80000000 | 67, QMetaType::QString,   68,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSettingsUI((*reinterpret_cast< appSettingsStruct(*)>(_a[1]))); break;
        case 1: _t->printConsole((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_DL_calibration_clicked(); break;
        case 3: _t->disable_all_widgets(); break;
        case 4: _t->reset_all_widgets(); break;
        case 5: _t->on_pushButton_DL_write_clicked(); break;
        case 6: _t->on_pushButton_DL_multimeter_clicked(); break;
        case 7: _t->on_pushButton_UL_calibration_clicked(); break;
        case 8: _t->on_pushButton_UL_multimeter_clicked(); break;
        case 9: _t->on_pushButton_UL_write_clicked(); break;
        case 10: _t->on_pushButton_mmpersec_calibration_clicked(); break;
        case 11: _t->on_pushButton_mmpersec_write_clicked(); break;
        case 12: _t->on_pushButton_calibrate_device_clicked(); break;
        case 13: _t->on_pushButton_COM_connect_clicked(); break;
        case 14: _t->receiveMessage(); break;
        case 15: _t->plotGraph((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->on_pushButton_dynamic_range_set_clicked(); break;
        case 17: _t->on_pushButton_dynamic_range_write_clicked(); break;
        case 18: _t->on_pushButton_manual_clicked(); break;
        case 19: { bool _r = _t->serialPortCheckout();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->slotMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 21: _t->slotMouseDoubleClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 22: _t->slotMousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 23: _t->slotMouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 24: _t->slotSavePlotPNG(); break;
        case 25: _t->slotResetCanvas(); break;
        case 26: _t->slotSaveDataFromPlot(); break;
        case 27: _t->on_pushButton_settings_clicked(); break;
        case 28: _t->initializeConnects(); break;
        case 29: _t->initializeAppSettings(); break;
        case 30: _t->initializeMenu(); break;
        case 31: _t->initializeCanvas(); break;
        case 32: _t->saveAppSettings((*reinterpret_cast< appSettingsStruct(*)>(_a[1]))); break;
        case 33: _t->on_pushButton_userCommand_clicked(); break;
        case 34: _t->serialGetConfig(); break;
        case 35: _t->slotClearCanvas(); break;
        case 36: _t->slotClearConsole(); break;
        case 37: _t->slotClearAll(); break;
        case 38: _t->on_pushButton_thermoslope_set_clicked(); break;
        case 39: _t->on_pushButton_thermoslope_write_clicked(); break;
        case 40: _t->on_pushButton_constant_value_set_clicked(); break;
        case 41: _t->on_pushButton_thermointercept_set_clicked(); break;
        case 42: _t->on_pushButton_thermointercept_write_clicked(); break;
        case 43: _t->on_pushButton_constant_value_write_clicked(); break;
        case 44: _t->on_pushButton_default_settings_set_clicked(); break;
        case 45: _t->on_pushButton_thermo_lowTemperature_constant_set_clicked(); break;
        case 46: _t->on_pushButton_thermo_lowTemperature_constant_write_clicked(); break;
        case 47: _t->on_pushButton_thermohelp_clicked(); break;
        case 48: _t->updateComboBoxValue((*reinterpret_cast< QComboBox*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 49: _t->updateLineEditValue((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 50: _t->handleInitMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 51: _t->updateSpinBoxValue((*reinterpret_cast< QSpinBox*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 52: _t->on_pushButton_axis_write_clicked(); break;
        case 53: _t->on_pushButton_measuring_axis_set_clicked(); break;
        case 54: _t->on_pushButton_measuring_axis_write_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 48:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QComboBox* >(); break;
            }
            break;
        case 49:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 51:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSpinBox* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(appSettingsStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setSettingsUI)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::setSettingsUI(appSettingsStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
