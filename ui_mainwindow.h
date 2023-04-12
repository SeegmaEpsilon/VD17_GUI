/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 12. Apr 16:01:59 2023
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_DL_write;
    QComboBox *cmb_dynamic_ranges;
    QLineEdit *lineEdit_average_A;
    QPushButton *pushButton_UL_multimeter;
    QPushButton *pushButton_get_config;
    QPushButton *pushButton_clear_canvas;
    QTextEdit *UART_output;
    QLineEdit *lineEdit_average_V;
    QPushButton *pushButton_COM_connect;
    QSpinBox *lineEdit_UL_value;
    QPushButton *pushButton_DL_multimeter;
    QPushButton *pushButton_clear_console;
    QSpinBox *lineEdit_DL_value;
    QLabel *label_acceleration_RMS;
    QPushButton *pushButton_dynamic_range_write;
    QLabel *label;
    QComboBox *cmb_mmpersec;
    QPushButton *pushButton_dynamic_range_set;
    QLineEdit *lineEdit_RMS_A;
    QPushButton *pushButton_DL_calibration;
    QPushButton *pushButton_UL_calibration;
    QLineEdit *lineEdit_RMS_V;
    QPushButton *pushButton_UL_write;
    QLabel *label_port;
    QPushButton *pushButton_mmpersec_write;
    QPushButton *pushButton_mmpersec_calibration;
    QPushButton *pushButton_calibrate_device;
    QComboBox *comboBox_port;
    QPushButton *pushButton_manual;
    QCheckBox *checkBox_need_plot;
    QCustomPlot *canvas;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1086, 560);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_DL_write = new QPushButton(centralWidget);
        pushButton_DL_write->setObjectName(QString::fromUtf8("pushButton_DL_write"));
        pushButton_DL_write->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_DL_write->sizePolicy().hasHeightForWidth());
        pushButton_DL_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_DL_write, 2, 4, 1, 1);

        cmb_dynamic_ranges = new QComboBox(centralWidget);
        cmb_dynamic_ranges->setObjectName(QString::fromUtf8("cmb_dynamic_ranges"));
        cmb_dynamic_ranges->setEnabled(false);

        gridLayout->addWidget(cmb_dynamic_ranges, 5, 2, 1, 1);

        lineEdit_average_A = new QLineEdit(centralWidget);
        lineEdit_average_A->setObjectName(QString::fromUtf8("lineEdit_average_A"));
        sizePolicy.setHeightForWidth(lineEdit_average_A->sizePolicy().hasHeightForWidth());
        lineEdit_average_A->setSizePolicy(sizePolicy);
        lineEdit_average_A->setMaximumSize(QSize(80, 16777215));
        lineEdit_average_A->setAlignment(Qt::AlignCenter);
        lineEdit_average_A->setReadOnly(true);

        gridLayout->addWidget(lineEdit_average_A, 6, 4, 1, 1);

        pushButton_UL_multimeter = new QPushButton(centralWidget);
        pushButton_UL_multimeter->setObjectName(QString::fromUtf8("pushButton_UL_multimeter"));
        pushButton_UL_multimeter->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_UL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_UL_multimeter->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_UL_multimeter, 3, 3, 1, 1);

        pushButton_get_config = new QPushButton(centralWidget);
        pushButton_get_config->setObjectName(QString::fromUtf8("pushButton_get_config"));

        gridLayout->addWidget(pushButton_get_config, 1, 0, 1, 3);

        pushButton_clear_canvas = new QPushButton(centralWidget);
        pushButton_clear_canvas->setObjectName(QString::fromUtf8("pushButton_clear_canvas"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_clear_canvas->sizePolicy().hasHeightForWidth());
        pushButton_clear_canvas->setSizePolicy(sizePolicy1);
        pushButton_clear_canvas->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(pushButton_clear_canvas, 9, 7, 1, 1);

        UART_output = new QTextEdit(centralWidget);
        UART_output->setObjectName(QString::fromUtf8("UART_output"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(UART_output->sizePolicy().hasHeightForWidth());
        UART_output->setSizePolicy(sizePolicy2);
        UART_output->setMinimumSize(QSize(0, 0));
        UART_output->setReadOnly(true);

        gridLayout->addWidget(UART_output, 8, 0, 2, 5);

        lineEdit_average_V = new QLineEdit(centralWidget);
        lineEdit_average_V->setObjectName(QString::fromUtf8("lineEdit_average_V"));
        sizePolicy.setHeightForWidth(lineEdit_average_V->sizePolicy().hasHeightForWidth());
        lineEdit_average_V->setSizePolicy(sizePolicy);
        lineEdit_average_V->setMaximumSize(QSize(80, 16777215));
        lineEdit_average_V->setAlignment(Qt::AlignCenter);
        lineEdit_average_V->setReadOnly(true);

        gridLayout->addWidget(lineEdit_average_V, 7, 4, 1, 1);

        pushButton_COM_connect = new QPushButton(centralWidget);
        pushButton_COM_connect->setObjectName(QString::fromUtf8("pushButton_COM_connect"));
        sizePolicy.setHeightForWidth(pushButton_COM_connect->sizePolicy().hasHeightForWidth());
        pushButton_COM_connect->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_COM_connect, 0, 3, 1, 2);

        lineEdit_UL_value = new QSpinBox(centralWidget);
        lineEdit_UL_value->setObjectName(QString::fromUtf8("lineEdit_UL_value"));
        lineEdit_UL_value->setEnabled(false);
        lineEdit_UL_value->setAlignment(Qt::AlignCenter);
        lineEdit_UL_value->setMaximum(9999);
        lineEdit_UL_value->setValue(1600);

        gridLayout->addWidget(lineEdit_UL_value, 3, 2, 1, 1);

        pushButton_DL_multimeter = new QPushButton(centralWidget);
        pushButton_DL_multimeter->setObjectName(QString::fromUtf8("pushButton_DL_multimeter"));
        pushButton_DL_multimeter->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_DL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_DL_multimeter->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_DL_multimeter, 2, 3, 1, 1);

        pushButton_clear_console = new QPushButton(centralWidget);
        pushButton_clear_console->setObjectName(QString::fromUtf8("pushButton_clear_console"));
        sizePolicy1.setHeightForWidth(pushButton_clear_console->sizePolicy().hasHeightForWidth());
        pushButton_clear_console->setSizePolicy(sizePolicy1);
        pushButton_clear_console->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(pushButton_clear_console, 9, 6, 1, 1);

        lineEdit_DL_value = new QSpinBox(centralWidget);
        lineEdit_DL_value->setObjectName(QString::fromUtf8("lineEdit_DL_value"));
        lineEdit_DL_value->setEnabled(false);
        lineEdit_DL_value->setAlignment(Qt::AlignCenter);
        lineEdit_DL_value->setMaximum(9999);
        lineEdit_DL_value->setValue(100);

        gridLayout->addWidget(lineEdit_DL_value, 2, 2, 1, 1);

        label_acceleration_RMS = new QLabel(centralWidget);
        label_acceleration_RMS->setObjectName(QString::fromUtf8("label_acceleration_RMS"));
        label_acceleration_RMS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_acceleration_RMS, 6, 0, 1, 3);

        pushButton_dynamic_range_write = new QPushButton(centralWidget);
        pushButton_dynamic_range_write->setObjectName(QString::fromUtf8("pushButton_dynamic_range_write"));
        pushButton_dynamic_range_write->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_dynamic_range_write->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_dynamic_range_write, 5, 3, 1, 2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 7, 0, 1, 3);

        cmb_mmpersec = new QComboBox(centralWidget);
        cmb_mmpersec->setObjectName(QString::fromUtf8("cmb_mmpersec"));
        cmb_mmpersec->setEnabled(false);

        gridLayout->addWidget(cmb_mmpersec, 4, 2, 1, 1);

        pushButton_dynamic_range_set = new QPushButton(centralWidget);
        pushButton_dynamic_range_set->setObjectName(QString::fromUtf8("pushButton_dynamic_range_set"));
        sizePolicy.setHeightForWidth(pushButton_dynamic_range_set->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_set->setSizePolicy(sizePolicy);
        pushButton_dynamic_range_set->setMinimumSize(QSize(215, 0));
        pushButton_dynamic_range_set->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(pushButton_dynamic_range_set, 5, 0, 1, 2);

        lineEdit_RMS_A = new QLineEdit(centralWidget);
        lineEdit_RMS_A->setObjectName(QString::fromUtf8("lineEdit_RMS_A"));
        sizePolicy.setHeightForWidth(lineEdit_RMS_A->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_A->setSizePolicy(sizePolicy);
        lineEdit_RMS_A->setMaximumSize(QSize(80, 16777215));
        lineEdit_RMS_A->setAlignment(Qt::AlignCenter);
        lineEdit_RMS_A->setReadOnly(true);

        gridLayout->addWidget(lineEdit_RMS_A, 6, 3, 1, 1);

        pushButton_DL_calibration = new QPushButton(centralWidget);
        pushButton_DL_calibration->setObjectName(QString::fromUtf8("pushButton_DL_calibration"));
        sizePolicy.setHeightForWidth(pushButton_DL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_DL_calibration->setSizePolicy(sizePolicy);
        pushButton_DL_calibration->setLayoutDirection(Qt::LeftToRight);
        pushButton_DL_calibration->setAutoFillBackground(false);
        pushButton_DL_calibration->setAutoRepeat(false);
        pushButton_DL_calibration->setAutoExclusive(false);
        pushButton_DL_calibration->setAutoDefault(false);

        gridLayout->addWidget(pushButton_DL_calibration, 2, 0, 1, 2);

        pushButton_UL_calibration = new QPushButton(centralWidget);
        pushButton_UL_calibration->setObjectName(QString::fromUtf8("pushButton_UL_calibration"));
        sizePolicy.setHeightForWidth(pushButton_UL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_UL_calibration->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_UL_calibration, 3, 0, 1, 2);

        lineEdit_RMS_V = new QLineEdit(centralWidget);
        lineEdit_RMS_V->setObjectName(QString::fromUtf8("lineEdit_RMS_V"));
        sizePolicy.setHeightForWidth(lineEdit_RMS_V->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_V->setSizePolicy(sizePolicy);
        lineEdit_RMS_V->setMaximumSize(QSize(80, 16777215));
        lineEdit_RMS_V->setAlignment(Qt::AlignCenter);
        lineEdit_RMS_V->setReadOnly(true);

        gridLayout->addWidget(lineEdit_RMS_V, 7, 3, 1, 1);

        pushButton_UL_write = new QPushButton(centralWidget);
        pushButton_UL_write->setObjectName(QString::fromUtf8("pushButton_UL_write"));
        pushButton_UL_write->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_UL_write->sizePolicy().hasHeightForWidth());
        pushButton_UL_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_UL_write, 3, 4, 1, 1);

        label_port = new QLabel(centralWidget);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        sizePolicy2.setHeightForWidth(label_port->sizePolicy().hasHeightForWidth());
        label_port->setSizePolicy(sizePolicy2);
        label_port->setMaximumSize(QSize(60, 16777215));
        label_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_port, 0, 0, 1, 1);

        pushButton_mmpersec_write = new QPushButton(centralWidget);
        pushButton_mmpersec_write->setObjectName(QString::fromUtf8("pushButton_mmpersec_write"));
        pushButton_mmpersec_write->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_mmpersec_write->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_mmpersec_write, 4, 3, 1, 2);

        pushButton_mmpersec_calibration = new QPushButton(centralWidget);
        pushButton_mmpersec_calibration->setObjectName(QString::fromUtf8("pushButton_mmpersec_calibration"));
        pushButton_mmpersec_calibration->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_mmpersec_calibration->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_calibration->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_mmpersec_calibration, 4, 0, 1, 2);

        pushButton_calibrate_device = new QPushButton(centralWidget);
        pushButton_calibrate_device->setObjectName(QString::fromUtf8("pushButton_calibrate_device"));
        pushButton_calibrate_device->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_calibrate_device->sizePolicy().hasHeightForWidth());
        pushButton_calibrate_device->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_calibrate_device, 1, 3, 1, 2);

        comboBox_port = new QComboBox(centralWidget);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));

        gridLayout->addWidget(comboBox_port, 0, 1, 1, 2);

        pushButton_manual = new QPushButton(centralWidget);
        pushButton_manual->setObjectName(QString::fromUtf8("pushButton_manual"));
        pushButton_manual->setMinimumSize(QSize(180, 21));
        pushButton_manual->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  border: 1px solid gray;\n"
"  background-color:rgba(0, 0, 255, 20);\n"
"  border-radius: 5px;\n"
"} \n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(0, 0, 255, 30);\n"
"   border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(pushButton_manual, 9, 8, 1, 1);

        checkBox_need_plot = new QCheckBox(centralWidget);
        checkBox_need_plot->setObjectName(QString::fromUtf8("checkBox_need_plot"));

        gridLayout->addWidget(checkBox_need_plot, 9, 5, 1, 1);

        canvas = new QCustomPlot(centralWidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy3);
        canvas->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(canvas, 0, 5, 9, 4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1086, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        cmb_dynamic_ranges->setCurrentIndex(3);
        cmb_mmpersec->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton_DL_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        cmb_dynamic_ranges->clear();
        cmb_dynamic_ranges->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2g", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4g", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8g", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16g", 0, QApplication::UnicodeUTF8)
        );
        pushButton_UL_multimeter->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", 0, QApplication::UnicodeUTF8));
        pushButton_get_config->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\272\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\321\216 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_clear_canvas->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 \320\270 \320\264\320\260\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        pushButton_COM_connect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        pushButton_DL_multimeter->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", 0, QApplication::UnicodeUTF8));
        pushButton_clear_console->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\272\320\276\320\275\321\201\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        label_acceleration_RMS->setText(QApplication::translate("MainWindow", "\320\234\320\263\320\275\320\276\320\262\320\265\320\275\320\275\320\276\320\265/\321\201\321\200\320\265\320\264\320\275\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\241\320\232\320\227 \321\203\321\201\320\272\320\276\321\200\320\265\320\275\320\270\321\217 A [\320\274/\321\2012] =", 0, QApplication::UnicodeUTF8));
        pushButton_dynamic_range_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\234\320\263\320\275\320\276\320\262\320\265\320\275\320\275\320\276\320\265/\321\201\321\200\320\265\320\264\320\275\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\241\320\232\320\227 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270   V [\320\274\320\274/\321\201] =", 0, QApplication::UnicodeUTF8));
        cmb_mmpersec->clear();
        cmb_mmpersec->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "20 \320\274\320\274/\321\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "50 \320\274\320\274/\321\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100 \320\274\320\274/\321\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "200 \320\274\320\274/\321\201", 0, QApplication::UnicodeUTF8)
        );
        pushButton_dynamic_range_set->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\264\320\270\320\275\320\260\320\274\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_DL_calibration->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\320\270\320\266\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", 0, QApplication::UnicodeUTF8));
        pushButton_UL_calibration->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\262\320\265\321\200\321\205\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", 0, QApplication::UnicodeUTF8));
        pushButton_UL_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_port->setText(QApplication::translate("MainWindow", "COM-\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_mmpersec_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_mmpersec_calibration->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\271 \320\262\320\270\320\261\321\200\320\276\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_calibrate_device->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\321\202\321\207\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pushButton_manual->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217 \320\277\320\276 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\265 \320\222\320\22417", 0, QApplication::UnicodeUTF8));
        checkBox_need_plot->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
