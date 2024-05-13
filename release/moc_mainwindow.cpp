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
    char stringdata0[1480];
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
QT_MOC_LITERAL(5, 53, 14), // "processMessage"
QT_MOC_LITERAL(6, 68, 7), // "message"
QT_MOC_LITERAL(7, 76, 12), // "printConsole"
QT_MOC_LITERAL(8, 89, 6), // "string"
QT_MOC_LITERAL(9, 96, 30), // "on_pushButton_DL_write_clicked"
QT_MOC_LITERAL(10, 127, 30), // "on_pushButton_UL_write_clicked"
QT_MOC_LITERAL(11, 158, 36), // "on_pushButton_mmpersec_write_..."
QT_MOC_LITERAL(12, 195, 33), // "on_pushButton_COM_connect_cli..."
QT_MOC_LITERAL(13, 229, 41), // "on_pushButton_dynamic_range_w..."
QT_MOC_LITERAL(14, 271, 39), // "on_pushButton_thermoslope_wri..."
QT_MOC_LITERAL(15, 311, 43), // "on_pushButton_thermointercept..."
QT_MOC_LITERAL(16, 355, 42), // "on_pushButton_constant_value_..."
QT_MOC_LITERAL(17, 398, 42), // "on_pushButton_default_setting..."
QT_MOC_LITERAL(18, 441, 32), // "on_pushButton_get_config_clicked"
QT_MOC_LITERAL(19, 474, 58), // "on_pushButton_thermo_lowTempe..."
QT_MOC_LITERAL(20, 533, 42), // "on_pushButton_measuring_axis_..."
QT_MOC_LITERAL(21, 576, 46), // "on_pushButton_constant_compon..."
QT_MOC_LITERAL(22, 623, 47), // "on_pushButton_measuring_param..."
QT_MOC_LITERAL(23, 671, 32), // "on_pushButton_axis_write_clicked"
QT_MOC_LITERAL(24, 704, 14), // "receiveMessage"
QT_MOC_LITERAL(25, 719, 28), // "on_pushButton_manual_clicked"
QT_MOC_LITERAL(26, 748, 18), // "serialPortCheckout"
QT_MOC_LITERAL(27, 767, 13), // "slotMouseMove"
QT_MOC_LITERAL(28, 781, 12), // "QMouseEvent*"
QT_MOC_LITERAL(29, 794, 5), // "event"
QT_MOC_LITERAL(30, 800, 20), // "slotMouseDoubleClick"
QT_MOC_LITERAL(31, 821, 14), // "slotMousePress"
QT_MOC_LITERAL(32, 836, 16), // "slotMouseRelease"
QT_MOC_LITERAL(33, 853, 15), // "slotSavePlotPNG"
QT_MOC_LITERAL(34, 869, 15), // "slotResetCanvas"
QT_MOC_LITERAL(35, 885, 20), // "slotSaveDataFromPlot"
QT_MOC_LITERAL(36, 906, 30), // "on_pushButton_settings_clicked"
QT_MOC_LITERAL(37, 937, 18), // "initializeConnects"
QT_MOC_LITERAL(38, 956, 21), // "initializeAppSettings"
QT_MOC_LITERAL(39, 978, 14), // "initializeMenu"
QT_MOC_LITERAL(40, 993, 15), // "saveAppSettings"
QT_MOC_LITERAL(41, 1009, 12), // "tempSettings"
QT_MOC_LITERAL(42, 1022, 33), // "on_pushButton_userCommand_cli..."
QT_MOC_LITERAL(43, 1056, 15), // "slotClearCanvas"
QT_MOC_LITERAL(44, 1072, 16), // "slotClearConsole"
QT_MOC_LITERAL(45, 1089, 12), // "slotClearAll"
QT_MOC_LITERAL(46, 1102, 32), // "on_pushButton_thermohelp_clicked"
QT_MOC_LITERAL(47, 1135, 19), // "updateComboBoxValue"
QT_MOC_LITERAL(48, 1155, 10), // "QComboBox*"
QT_MOC_LITERAL(49, 1166, 8), // "comboBox"
QT_MOC_LITERAL(50, 1175, 19), // "updateLineEditValue"
QT_MOC_LITERAL(51, 1195, 10), // "QLineEdit*"
QT_MOC_LITERAL(52, 1206, 8), // "lineEdit"
QT_MOC_LITERAL(53, 1215, 17), // "handleInitMessage"
QT_MOC_LITERAL(54, 1233, 18), // "updateSpinBoxValue"
QT_MOC_LITERAL(55, 1252, 9), // "QSpinBox*"
QT_MOC_LITERAL(56, 1262, 7), // "spinBox"
QT_MOC_LITERAL(57, 1270, 15), // "setupGraphsOnce"
QT_MOC_LITERAL(58, 1286, 12), // "canvas_index"
QT_MOC_LITERAL(59, 1299, 7), // "from_ui"
QT_MOC_LITERAL(60, 1307, 9), // "plotGraph"
QT_MOC_LITERAL(61, 1317, 10), // "graphIndex"
QT_MOC_LITERAL(62, 1328, 7), // "float_t"
QT_MOC_LITERAL(63, 1336, 5), // "value"
QT_MOC_LITERAL(64, 1342, 13), // "writeToSerial"
QT_MOC_LITERAL(65, 1356, 11), // "const char*"
QT_MOC_LITERAL(66, 1368, 7), // "command"
QT_MOC_LITERAL(67, 1376, 11), // "sendCommand"
QT_MOC_LITERAL(68, 1388, 11), // "commandBase"
QT_MOC_LITERAL(69, 1400, 41), // "on_cmb_graph_selector_current..."
QT_MOC_LITERAL(70, 1442, 5), // "index"
QT_MOC_LITERAL(71, 1448, 10), // "handleAxis"
QT_MOC_LITERAL(72, 1459, 8), // "graphRow"
QT_MOC_LITERAL(73, 1468, 11) // "graphColumn"

    },
    "MainWindow\0setSettingsUI\0\0appSettingsStruct\0"
    "settings\0processMessage\0message\0"
    "printConsole\0string\0on_pushButton_DL_write_clicked\0"
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
    "receiveMessage\0on_pushButton_manual_clicked\0"
    "serialPortCheckout\0slotMouseMove\0"
    "QMouseEvent*\0event\0slotMouseDoubleClick\0"
    "slotMousePress\0slotMouseRelease\0"
    "slotSavePlotPNG\0slotResetCanvas\0"
    "slotSaveDataFromPlot\0"
    "on_pushButton_settings_clicked\0"
    "initializeConnects\0initializeAppSettings\0"
    "initializeMenu\0saveAppSettings\0"
    "tempSettings\0on_pushButton_userCommand_clicked\0"
    "slotClearCanvas\0slotClearConsole\0"
    "slotClearAll\0on_pushButton_thermohelp_clicked\0"
    "updateComboBoxValue\0QComboBox*\0comboBox\0"
    "updateLineEditValue\0QLineEdit*\0lineEdit\0"
    "handleInitMessage\0updateSpinBoxValue\0"
    "QSpinBox*\0spinBox\0setupGraphsOnce\0"
    "canvas_index\0from_ui\0plotGraph\0"
    "graphIndex\0float_t\0value\0writeToSerial\0"
    "const char*\0command\0sendCommand\0"
    "commandBase\0on_cmb_graph_selector_currentIndexChanged\0"
    "index\0handleAxis\0graphRow\0graphColumn"
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
       5,    1,  272,    2, 0x08 /* Private */,
       7,    1,  275,    2, 0x08 /* Private */,
       9,    0,  278,    2, 0x08 /* Private */,
      10,    0,  279,    2, 0x08 /* Private */,
      11,    0,  280,    2, 0x08 /* Private */,
      12,    0,  281,    2, 0x08 /* Private */,
      13,    0,  282,    2, 0x08 /* Private */,
      14,    0,  283,    2, 0x08 /* Private */,
      15,    0,  284,    2, 0x08 /* Private */,
      16,    0,  285,    2, 0x08 /* Private */,
      17,    0,  286,    2, 0x08 /* Private */,
      18,    0,  287,    2, 0x08 /* Private */,
      19,    0,  288,    2, 0x08 /* Private */,
      20,    0,  289,    2, 0x08 /* Private */,
      21,    0,  290,    2, 0x08 /* Private */,
      22,    0,  291,    2, 0x08 /* Private */,
      23,    0,  292,    2, 0x08 /* Private */,
      24,    0,  293,    2, 0x08 /* Private */,
      25,    0,  294,    2, 0x08 /* Private */,
      26,    0,  295,    2, 0x08 /* Private */,
      27,    1,  296,    2, 0x08 /* Private */,
      30,    1,  299,    2, 0x08 /* Private */,
      31,    1,  302,    2, 0x08 /* Private */,
      32,    1,  305,    2, 0x08 /* Private */,
      33,    0,  308,    2, 0x08 /* Private */,
      34,    0,  309,    2, 0x08 /* Private */,
      35,    0,  310,    2, 0x08 /* Private */,
      36,    0,  311,    2, 0x08 /* Private */,
      37,    0,  312,    2, 0x08 /* Private */,
      38,    0,  313,    2, 0x08 /* Private */,
      39,    0,  314,    2, 0x08 /* Private */,
      40,    1,  315,    2, 0x08 /* Private */,
      42,    0,  318,    2, 0x08 /* Private */,
      43,    0,  319,    2, 0x08 /* Private */,
      44,    0,  320,    2, 0x08 /* Private */,
      45,    0,  321,    2, 0x08 /* Private */,
      46,    0,  322,    2, 0x08 /* Private */,
      47,    2,  323,    2, 0x08 /* Private */,
      50,    2,  328,    2, 0x08 /* Private */,
      53,    1,  333,    2, 0x08 /* Private */,
      54,    2,  336,    2, 0x08 /* Private */,
      57,    2,  341,    2, 0x08 /* Private */,
      57,    1,  346,    2, 0x28 /* Private | MethodCloned */,
      60,    3,  349,    2, 0x08 /* Private */,
      64,    1,  356,    2, 0x08 /* Private */,
      67,    2,  359,    2, 0x08 /* Private */,
      67,    2,  364,    2, 0x08 /* Private */,
      67,    2,  369,    2, 0x08 /* Private */,
      69,    1,  374,    2, 0x08 /* Private */,
      71,    4,  377,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
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
    QMetaType::Void, 0x80000000 | 3,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 48, QMetaType::QString,   49,    6,
    QMetaType::Void, 0x80000000 | 51, QMetaType::QString,   52,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 55, QMetaType::QString,   56,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   58,   59,
    QMetaType::Void, QMetaType::Int,   58,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 62,   58,   61,   63,
    QMetaType::Void, 0x80000000 | 65,   66,
    QMetaType::Void, 0x80000000 | 65, 0x80000000 | 51,   68,   52,
    QMetaType::Void, 0x80000000 | 65, 0x80000000 | 48,   68,   49,
    QMetaType::Void, 0x80000000 | 65, 0x80000000 | 55,   68,   56,
    QMetaType::Void, QMetaType::Int,   70,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 51, QMetaType::Int, QMetaType::Int,    6,   52,   72,   73,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSettingsUI((*reinterpret_cast< appSettingsStruct(*)>(_a[1]))); break;
        case 1: _t->processMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->printConsole((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_DL_write_clicked(); break;
        case 4: _t->on_pushButton_UL_write_clicked(); break;
        case 5: _t->on_pushButton_mmpersec_write_clicked(); break;
        case 6: _t->on_pushButton_COM_connect_clicked(); break;
        case 7: _t->on_pushButton_dynamic_range_write_clicked(); break;
        case 8: _t->on_pushButton_thermoslope_write_clicked(); break;
        case 9: _t->on_pushButton_thermointercept_write_clicked(); break;
        case 10: _t->on_pushButton_constant_value_write_clicked(); break;
        case 11: _t->on_pushButton_default_settings_set_clicked(); break;
        case 12: _t->on_pushButton_get_config_clicked(); break;
        case 13: _t->on_pushButton_thermo_lowTemperature_constant_write_clicked(); break;
        case 14: _t->on_pushButton_measuring_axis_write_clicked(); break;
        case 15: _t->on_pushButton_constant_component_write_clicked(); break;
        case 16: _t->on_pushButton_measuring_parameter_write_clicked(); break;
        case 17: _t->on_pushButton_axis_write_clicked(); break;
        case 18: _t->receiveMessage(); break;
        case 19: _t->on_pushButton_manual_clicked(); break;
        case 20: { bool _r = _t->serialPortCheckout();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->slotMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 22: _t->slotMouseDoubleClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 23: _t->slotMousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 24: _t->slotMouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 25: _t->slotSavePlotPNG(); break;
        case 26: _t->slotResetCanvas(); break;
        case 27: _t->slotSaveDataFromPlot(); break;
        case 28: _t->on_pushButton_settings_clicked(); break;
        case 29: _t->initializeConnects(); break;
        case 30: _t->initializeAppSettings(); break;
        case 31: _t->initializeMenu(); break;
        case 32: _t->saveAppSettings((*reinterpret_cast< appSettingsStruct(*)>(_a[1]))); break;
        case 33: _t->on_pushButton_userCommand_clicked(); break;
        case 34: _t->slotClearCanvas(); break;
        case 35: _t->slotClearConsole(); break;
        case 36: _t->slotClearAll(); break;
        case 37: _t->on_pushButton_thermohelp_clicked(); break;
        case 38: _t->updateComboBoxValue((*reinterpret_cast< QComboBox*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 39: _t->updateLineEditValue((*reinterpret_cast< QLineEdit*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 40: _t->handleInitMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->updateSpinBoxValue((*reinterpret_cast< QSpinBox*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 42: _t->setupGraphsOnce((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 43: _t->setupGraphsOnce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->plotGraph((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float_t(*)>(_a[3]))); break;
        case 45: _t->writeToSerial((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 46: _t->sendCommand((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2]))); break;
        case 47: _t->sendCommand((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< QComboBox*(*)>(_a[2]))); break;
        case 48: _t->sendCommand((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< QSpinBox*(*)>(_a[2]))); break;
        case 49: _t->on_cmb_graph_selector_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->handleAxis((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QLineEdit*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QComboBox* >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSpinBox* >(); break;
            }
            break;
        case 46:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        case 47:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QComboBox* >(); break;
            }
            break;
        case 48:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QSpinBox* >(); break;
            }
            break;
        case 50:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
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
