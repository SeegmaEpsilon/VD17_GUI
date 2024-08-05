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
    QByteArrayData data[74];
    char stringdata0[1484];
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
QT_MOC_LITERAL(5, 53, 18), // "serialPortCheckout"
QT_MOC_LITERAL(6, 72, 14), // "processMessage"
QT_MOC_LITERAL(7, 87, 7), // "message"
QT_MOC_LITERAL(8, 95, 13), // "writeToSerial"
QT_MOC_LITERAL(9, 109, 11), // "const char*"
QT_MOC_LITERAL(10, 121, 7), // "command"
QT_MOC_LITERAL(11, 129, 11), // "sendCommand"
QT_MOC_LITERAL(12, 141, 11), // "commandBase"
QT_MOC_LITERAL(13, 153, 10), // "QLineEdit*"
QT_MOC_LITERAL(14, 164, 8), // "lineEdit"
QT_MOC_LITERAL(15, 173, 10), // "QComboBox*"
QT_MOC_LITERAL(16, 184, 8), // "comboBox"
QT_MOC_LITERAL(17, 193, 9), // "QSpinBox*"
QT_MOC_LITERAL(18, 203, 7), // "spinBox"
QT_MOC_LITERAL(19, 211, 10), // "handleAxis"
QT_MOC_LITERAL(20, 222, 8), // "graphRow"
QT_MOC_LITERAL(21, 231, 11), // "graphColumn"
QT_MOC_LITERAL(22, 243, 18), // "handleDebugMessage"
QT_MOC_LITERAL(23, 262, 17), // "handleInitMessage"
QT_MOC_LITERAL(24, 280, 12), // "printConsole"
QT_MOC_LITERAL(25, 293, 6), // "string"
QT_MOC_LITERAL(26, 300, 30), // "on_pushButton_DL_write_clicked"
QT_MOC_LITERAL(27, 331, 30), // "on_pushButton_UL_write_clicked"
QT_MOC_LITERAL(28, 362, 36), // "on_pushButton_mmpersec_write_..."
QT_MOC_LITERAL(29, 399, 33), // "on_pushButton_COM_connect_cli..."
QT_MOC_LITERAL(30, 433, 41), // "on_pushButton_dynamic_range_w..."
QT_MOC_LITERAL(31, 475, 39), // "on_pushButton_thermoslope_wri..."
QT_MOC_LITERAL(32, 515, 43), // "on_pushButton_thermointercept..."
QT_MOC_LITERAL(33, 559, 42), // "on_pushButton_constant_value_..."
QT_MOC_LITERAL(34, 602, 42), // "on_pushButton_default_setting..."
QT_MOC_LITERAL(35, 645, 32), // "on_pushButton_get_config_clicked"
QT_MOC_LITERAL(36, 678, 58), // "on_pushButton_thermo_lowTempe..."
QT_MOC_LITERAL(37, 737, 42), // "on_pushButton_measuring_axis_..."
QT_MOC_LITERAL(38, 780, 46), // "on_pushButton_constant_compon..."
QT_MOC_LITERAL(39, 827, 47), // "on_pushButton_measuring_param..."
QT_MOC_LITERAL(40, 875, 32), // "on_pushButton_axis_write_clicked"
QT_MOC_LITERAL(41, 908, 28), // "on_pushButton_manual_clicked"
QT_MOC_LITERAL(42, 937, 30), // "on_pushButton_settings_clicked"
QT_MOC_LITERAL(43, 968, 33), // "on_pushButton_userCommand_cli..."
QT_MOC_LITERAL(44, 1002, 32), // "on_pushButton_thermohelp_clicked"
QT_MOC_LITERAL(45, 1035, 13), // "slotMouseMove"
QT_MOC_LITERAL(46, 1049, 12), // "QMouseEvent*"
QT_MOC_LITERAL(47, 1062, 5), // "event"
QT_MOC_LITERAL(48, 1068, 20), // "slotMouseDoubleClick"
QT_MOC_LITERAL(49, 1089, 14), // "slotMousePress"
QT_MOC_LITERAL(50, 1104, 16), // "slotMouseRelease"
QT_MOC_LITERAL(51, 1121, 15), // "slotSavePlotPNG"
QT_MOC_LITERAL(52, 1137, 15), // "slotResetCanvas"
QT_MOC_LITERAL(53, 1153, 20), // "slotSaveDataFromPlot"
QT_MOC_LITERAL(54, 1174, 15), // "slotClearCanvas"
QT_MOC_LITERAL(55, 1190, 16), // "slotClearConsole"
QT_MOC_LITERAL(56, 1207, 12), // "slotClearAll"
QT_MOC_LITERAL(57, 1220, 18), // "initializeConnects"
QT_MOC_LITERAL(58, 1239, 21), // "initializeAppSettings"
QT_MOC_LITERAL(59, 1261, 14), // "initializeMenu"
QT_MOC_LITERAL(60, 1276, 15), // "saveAppSettings"
QT_MOC_LITERAL(61, 1292, 12), // "tempSettings"
QT_MOC_LITERAL(62, 1305, 19), // "updateComboBoxValue"
QT_MOC_LITERAL(63, 1325, 19), // "updateLineEditValue"
QT_MOC_LITERAL(64, 1345, 18), // "updateSpinBoxValue"
QT_MOC_LITERAL(65, 1364, 15), // "setupGraphsOnce"
QT_MOC_LITERAL(66, 1380, 12), // "canvas_index"
QT_MOC_LITERAL(67, 1393, 7), // "from_ui"
QT_MOC_LITERAL(68, 1401, 9), // "plotGraph"
QT_MOC_LITERAL(69, 1411, 10), // "graphIndex"
QT_MOC_LITERAL(70, 1422, 7), // "float_t"
QT_MOC_LITERAL(71, 1430, 5), // "value"
QT_MOC_LITERAL(72, 1436, 41), // "on_cmb_graph_selector_current..."
QT_MOC_LITERAL(73, 1478, 5) // "index"

    },
    "MainWindow\0setSettingsUI\0\0appSettingsStruct\0"
    "settings\0serialPortCheckout\0processMessage\0"
    "message\0writeToSerial\0const char*\0"
    "command\0sendCommand\0commandBase\0"
    "QLineEdit*\0lineEdit\0QComboBox*\0comboBox\0"
    "QSpinBox*\0spinBox\0handleAxis\0graphRow\0"
    "graphColumn\0handleDebugMessage\0"
    "handleInitMessage\0printConsole\0string\0"
    "on_pushButton_DL_write_clicked\0"
    "on_pushButton_UL_write_clicked\0"
    "on_pushButton_mmpersec_write_clicked\0"
    "on_pushButton_COM_connect_clicked\0"
    "on_pushButton_dynamic_range_write_clicked\0"
    "on_pushButton_thermoslope_write_clicked\0"
    "on_pushButton_thermointercept_write_clicked\0"
    "on_pushButton_constant_value_write_clicked\0"
    "on_pushButton_default_settings_set_clicked\0"
    "on_pushButton_get_config_clicked\0"
    "on_pushButton_thermo_lowTemperature_constant_write_clicked\0"
    "on_pushButton_measuring_axis_write_clicked\0"
    "on_pushButton_constant_component_write_clicked\0"
    "on_pushButton_measuring_parameter_write_clicked\0"
    "on_pushButton_axis_write_clicked\0"
    "on_pushButton_manual_clicked\0"
    "on_pushButton_settings_clicked\0"
    "on_pushButton_userCommand_clicked\0"
    "on_pushButton_thermohelp_clicked\0"
    "slotMouseMove\0QMouseEvent*\0event\0"
    "slotMouseDoubleClick\0slotMousePress\0"
    "slotMouseRelease\0slotSavePlotPNG\0"
    "slotResetCanvas\0slotSaveDataFromPlot\0"
    "slotClearCanvas\0slotClearConsole\0"
    "slotClearAll\0initializeConnects\0"
    "initializeAppSettings\0initializeMenu\0"
    "saveAppSettings\0tempSettings\0"
    "updateComboBoxValue\0updateLineEditValue\0"
    "updateSpinBoxValue\0setupGraphsOnce\0"
    "canvas_index\0from_ui\0plotGraph\0"
    "graphIndex\0float_t\0value\0"
    "on_cmb_graph_selector_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  269,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  272,    2, 0x08 /* Private */,
       6,    1,  273,    2, 0x08 /* Private */,
       8,    1,  276,    2, 0x08 /* Private */,
      11,    2,  279,    2, 0x08 /* Private */,
      11,    2,  284,    2, 0x08 /* Private */,
      11,    2,  289,    2, 0x08 /* Private */,
      19,    4,  294,    2, 0x08 /* Private */,
      22,    1,  303,    2, 0x08 /* Private */,
      23,    1,  306,    2, 0x08 /* Private */,
      24,    1,  309,    2, 0x08 /* Private */,
      26,    0,  312,    2, 0x08 /* Private */,
      27,    0,  313,    2, 0x08 /* Private */,
      28,    0,  314,    2, 0x08 /* Private */,
      29,    0,  315,    2, 0x08 /* Private */,
      30,    0,  316,    2, 0x08 /* Private */,
      31,    0,  317,    2, 0x08 /* Private */,
      32,    0,  318,    2, 0x08 /* Private */,
      33,    0,  319,    2, 0x08 /* Private */,
      34,    0,  320,    2, 0x08 /* Private */,
      35,    0,  321,    2, 0x08 /* Private */,
      36,    0,  322,    2, 0x08 /* Private */,
      37,    0,  323,    2, 0x08 /* Private */,
      38,    0,  324,    2, 0x08 /* Private */,
      39,    0,  325,    2, 0x08 /* Private */,
      40,    0,  326,    2, 0x08 /* Private */,
      41,    0,  327,    2, 0x08 /* Private */,
      42,    0,  328,    2, 0x08 /* Private */,
      43,    0,  329,    2, 0x08 /* Private */,
      44,    0,  330,    2, 0x08 /* Private */,
      45,    1,  331,    2, 0x08 /* Private */,
      48,    1,  334,    2, 0x08 /* Private */,
      49,    1,  337,    2, 0x08 /* Private */,
      50,    1,  340,    2, 0x08 /* Private */,
      51,    0,  343,    2, 0x08 /* Private */,
      52,    0,  344,    2, 0x08 /* Private */,
      53,    0,  345,    2, 0x08 /* Private */,
      54,    0,  346,    2, 0x08 /* Private */,
      55,    0,  347,    2, 0x08 /* Private */,
      56,    0,  348,    2, 0x08 /* Private */,
      57,    0,  349,    2, 0x08 /* Private */,
      58,    0,  350,    2, 0x08 /* Private */,
      59,    0,  351,    2, 0x08 /* Private */,
      60,    1,  352,    2, 0x08 /* Private */,
      62,    2,  355,    2, 0x08 /* Private */,
      63,    2,  360,    2, 0x08 /* Private */,
      64,    2,  365,    2, 0x08 /* Private */,
      65,    2,  370,    2, 0x08 /* Private */,
      65,    1,  375,    2, 0x28 /* Private | MethodCloned */,
      68,    3,  378,    2, 0x08 /* Private */,
      72,    1,  385,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 13,   12,   14,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 15,   12,   16,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 17,   12,   18,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13, QMetaType::Int, QMetaType::Int,    7,   14,   20,   21,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,   25,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   61,
    QMetaType::Void, 0x80000000 | 15, QMetaType::QString,   16,    7,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString,   14,    7,
    QMetaType::Void, 0x80000000 | 17, QMetaType::QString,   18,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   66,   67,
    QMetaType::Void, QMetaType::Int,   66,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 70,   66,   69,   71,
    QMetaType::Void, QMetaType::Int,   73,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSettingsUI((*reinterpret_cast< appSettingsStruct(*)>(_a[1]))); break;
        case 1: { bool _r = _t->serialPortCheckout();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->processMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->writeToSerial((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 4: _t->sendCommand((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2]))); break;
        case 5: _t->sendCommand((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< QComboBox*(*)>(_a[2]))); break;
        case 6: _t->sendCommand((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< QSpinBox*(*)>(_a[2]))); break;
        case 7: _t->handleAxis((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 8: _t->handleDebugMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->handleInitMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->printConsole((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_DL_write_clicked(); break;
        case 12: _t->on_pushButton_UL_write_clicked(); break;
        case 13: _t->on_pushButton_mmpersec_write_clicked(); break;
        case 14: _t->on_pushButton_COM_connect_clicked(); break;
        case 15: _t->on_pushButton_dynamic_range_write_clicked(); break;
        case 16: _t->on_pushButton_thermoslope_write_clicked(); break;
        case 17: _t->on_pushButton_thermointercept_write_clicked(); break;
        case 18: _t->on_pushButton_constant_value_write_clicked(); break;
        case 19: _t->on_pushButton_default_settings_set_clicked(); break;
        case 20: _t->on_pushButton_get_config_clicked(); break;
        case 21: _t->on_pushButton_thermo_lowTemperature_constant_write_clicked(); break;
        case 22: _t->on_pushButton_measuring_axis_write_clicked(); break;
        case 23: _t->on_pushButton_constant_component_write_clicked(); break;
        case 24: _t->on_pushButton_measuring_parameter_write_clicked(); break;
        case 25: _t->on_pushButton_axis_write_clicked(); break;
        case 26: _t->on_pushButton_manual_clicked(); break;
        case 27: _t->on_pushButton_settings_clicked(); break;
        case 28: _t->on_pushButton_userCommand_clicked(); break;
        case 29: _t->on_pushButton_thermohelp_clicked(); break;
        case 30: _t->slotMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 31: _t->slotMouseDoubleClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 32: _t->slotMousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 33: _t->slotMouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 34: _t->slotSavePlotPNG(); break;
        case 35: _t->slotResetCanvas(); break;
        case 36: _t->slotSaveDataFromPlot(); break;
        case 37: _t->slotClearCanvas(); break;
        case 38: _t->slotClearConsole(); break;
        case 39: _t->slotClearAll(); break;
        case 40: _t->initializeConnects(); break;
        case 41: _t->initializeAppSettings(); break;
        case 42: _t->initializeMenu(); break;
        case 43: _t->saveAppSettings((*reinterpret_cast< appSettingsStruct(*)>(_a[1]))); break;
        case 44: _t->updateComboBoxValue((*reinterpret_cast< QComboBox*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 45: _t->updateLineEditValue((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 46: _t->updateSpinBoxValue((*reinterpret_cast< QSpinBox*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 47: _t->setupGraphsOnce((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 48: _t->setupGraphsOnce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->plotGraph((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float_t(*)>(_a[3]))); break;
        case 50: _t->on_cmb_graph_selector_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QComboBox* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSpinBox* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 44:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QComboBox* >(); break;
            }
            break;
        case 45:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 46:
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
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 51)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 51;
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
