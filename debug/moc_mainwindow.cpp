/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 5. Jun 19:24:07 2023
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   31,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     121,   11,   11,   11, 0x08,
     142,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     195,   11,   11,   11, 0x08,
     233,   11,   11,   11, 0x08,
     272,   11,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,
     343,   11,   11,   11, 0x08,
     388,   11,   11,   11, 0x08,
     427,   11,   11,   11, 0x08,
     468,   11,   11,   11, 0x08,
     504,   11,   11,   11, 0x08,
     525,  521,   11,   11, 0x08,
     545,   11,   11,   11, 0x08,
     587,   11,   11,   11, 0x08,
     631,   11,   11,   11, 0x08,
     668,   11,   11,   11, 0x08,
     712,  706,   11,   11, 0x08,
     746,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0slotTimerTimeout()\0string\0"
    "printConsole(QString)\0"
    "on_pushButton_DL_calibration_clicked()\0"
    "disable_all_widgets()\0enable_all_widgets()\0"
    "reset_all_widgets()\0"
    "on_pushButton_DL_write_clicked()\0"
    "on_pushButton_DL_multimeter_clicked()\0"
    "on_pushButton_UL_calibration_clicked()\0"
    "on_pushButton_UL_multimeter_clicked()\0"
    "on_pushButton_UL_write_clicked()\0"
    "on_pushButton_mmpersec_calibration_clicked()\0"
    "on_pushButton_mmpersec_write_clicked()\0"
    "on_pushButton_calibrate_device_clicked()\0"
    "on_pushButton_COM_connect_clicked()\0"
    "receiveMessage()\0msg\0plotGraph(QString&)\0"
    "on_pushButton_dynamic_range_set_clicked()\0"
    "on_pushButton_dynamic_range_write_clicked()\0"
    "on_pushButton_clear_canvas_clicked()\0"
    "on_pushButton_clear_console_clicked()\0"
    "index\0on_comboBox_port_highlighted(int)\0"
    "on_pushButton_manual_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->slotTimerTimeout(); break;
        case 1: _t->printConsole((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_DL_calibration_clicked(); break;
        case 3: _t->disable_all_widgets(); break;
        case 4: _t->enable_all_widgets(); break;
        case 5: _t->reset_all_widgets(); break;
        case 6: _t->on_pushButton_DL_write_clicked(); break;
        case 7: _t->on_pushButton_DL_multimeter_clicked(); break;
        case 8: _t->on_pushButton_UL_calibration_clicked(); break;
        case 9: _t->on_pushButton_UL_multimeter_clicked(); break;
        case 10: _t->on_pushButton_UL_write_clicked(); break;
        case 11: _t->on_pushButton_mmpersec_calibration_clicked(); break;
        case 12: _t->on_pushButton_mmpersec_write_clicked(); break;
        case 13: _t->on_pushButton_calibrate_device_clicked(); break;
        case 14: _t->on_pushButton_COM_connect_clicked(); break;
        case 15: _t->receiveMessage(); break;
        case 16: _t->plotGraph((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->on_pushButton_dynamic_range_set_clicked(); break;
        case 18: _t->on_pushButton_dynamic_range_write_clicked(); break;
        case 19: _t->on_pushButton_clear_canvas_clicked(); break;
        case 20: _t->on_pushButton_clear_console_clicked(); break;
        case 21: _t->on_comboBox_port_highlighted((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 22: _t->on_pushButton_manual_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
