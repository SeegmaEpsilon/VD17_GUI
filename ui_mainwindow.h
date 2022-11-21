/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 21. Nov 20:52:28 2022
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
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
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
    QCustomPlot *canvas;
    QPushButton *pushButton_dynamic_range_set;
    QPushButton *pushButton_mmpersec_calibration;
    QLabel *label_port;
    QPushButton *pushButton_DL_multimeter;
    QPushButton *pushButton_UL_multimeter;
    QPushButton *pushButton_UL_write;
    QPushButton *pushButton_DL_write;
    QLineEdit *lineEdit_DL_value;
    QLineEdit *lineEdit_UL_value;
    QComboBox *cmb_dynamic_ranges;
    QPushButton *pushButton_dynamic_range_write;
    QPushButton *pushButton_calibrate_device;
    QPushButton *pushButton_mmpersec_write;
    QComboBox *cmb_mmpersec;
    QTextEdit *UART_output;
    QPushButton *pushButton_DL_calibration;
    QPushButton *pushButton_UL_calibration;
    QPushButton *pushButton_clear_canvas;
    QPushButton *pushButton_COM_connect;
    QComboBox *comboBox_port;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(964, 552);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        canvas = new QCustomPlot(centralWidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy);
        canvas->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(canvas, 0, 10, 8, 1);

        pushButton_dynamic_range_set = new QPushButton(centralWidget);
        pushButton_dynamic_range_set->setObjectName(QString::fromUtf8("pushButton_dynamic_range_set"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_dynamic_range_set->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_set->setSizePolicy(sizePolicy1);
        pushButton_dynamic_range_set->setMinimumSize(QSize(215, 0));
        pushButton_dynamic_range_set->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(pushButton_dynamic_range_set, 6, 0, 1, 1);

        pushButton_mmpersec_calibration = new QPushButton(centralWidget);
        pushButton_mmpersec_calibration->setObjectName(QString::fromUtf8("pushButton_mmpersec_calibration"));
        pushButton_mmpersec_calibration->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_mmpersec_calibration->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_calibration->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_mmpersec_calibration, 5, 0, 1, 1);

        label_port = new QLabel(centralWidget);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_port->sizePolicy().hasHeightForWidth());
        label_port->setSizePolicy(sizePolicy2);
        label_port->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_port, 0, 0, 1, 1);

        pushButton_DL_multimeter = new QPushButton(centralWidget);
        pushButton_DL_multimeter->setObjectName(QString::fromUtf8("pushButton_DL_multimeter"));
        pushButton_DL_multimeter->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_DL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_DL_multimeter->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_DL_multimeter, 2, 1, 1, 1);

        pushButton_UL_multimeter = new QPushButton(centralWidget);
        pushButton_UL_multimeter->setObjectName(QString::fromUtf8("pushButton_UL_multimeter"));
        pushButton_UL_multimeter->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_UL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_UL_multimeter->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_UL_multimeter, 4, 1, 1, 1);

        pushButton_UL_write = new QPushButton(centralWidget);
        pushButton_UL_write->setObjectName(QString::fromUtf8("pushButton_UL_write"));
        pushButton_UL_write->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_UL_write->sizePolicy().hasHeightForWidth());
        pushButton_UL_write->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_UL_write, 3, 2, 1, 1);

        pushButton_DL_write = new QPushButton(centralWidget);
        pushButton_DL_write->setObjectName(QString::fromUtf8("pushButton_DL_write"));
        pushButton_DL_write->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_DL_write->sizePolicy().hasHeightForWidth());
        pushButton_DL_write->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_DL_write, 1, 2, 1, 1);

        lineEdit_DL_value = new QLineEdit(centralWidget);
        lineEdit_DL_value->setObjectName(QString::fromUtf8("lineEdit_DL_value"));
        lineEdit_DL_value->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_DL_value->sizePolicy().hasHeightForWidth());
        lineEdit_DL_value->setSizePolicy(sizePolicy1);
        lineEdit_DL_value->setMaxLength(3);
        lineEdit_DL_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_DL_value, 1, 1, 1, 1);

        lineEdit_UL_value = new QLineEdit(centralWidget);
        lineEdit_UL_value->setObjectName(QString::fromUtf8("lineEdit_UL_value"));
        lineEdit_UL_value->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_UL_value->sizePolicy().hasHeightForWidth());
        lineEdit_UL_value->setSizePolicy(sizePolicy1);
        lineEdit_UL_value->setMaxLength(4);
        lineEdit_UL_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_UL_value, 3, 1, 1, 1);

        cmb_dynamic_ranges = new QComboBox(centralWidget);
        cmb_dynamic_ranges->setObjectName(QString::fromUtf8("cmb_dynamic_ranges"));
        cmb_dynamic_ranges->setEnabled(false);

        gridLayout->addWidget(cmb_dynamic_ranges, 6, 1, 1, 1);

        pushButton_dynamic_range_write = new QPushButton(centralWidget);
        pushButton_dynamic_range_write->setObjectName(QString::fromUtf8("pushButton_dynamic_range_write"));
        pushButton_dynamic_range_write->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_dynamic_range_write->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_write->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_dynamic_range_write, 6, 2, 1, 1);

        pushButton_calibrate_device = new QPushButton(centralWidget);
        pushButton_calibrate_device->setObjectName(QString::fromUtf8("pushButton_calibrate_device"));
        pushButton_calibrate_device->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_calibrate_device->sizePolicy().hasHeightForWidth());
        pushButton_calibrate_device->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_calibrate_device, 8, 0, 1, 3);

        pushButton_mmpersec_write = new QPushButton(centralWidget);
        pushButton_mmpersec_write->setObjectName(QString::fromUtf8("pushButton_mmpersec_write"));
        pushButton_mmpersec_write->setEnabled(false);
        sizePolicy1.setHeightForWidth(pushButton_mmpersec_write->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_write->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_mmpersec_write, 5, 2, 1, 1);

        cmb_mmpersec = new QComboBox(centralWidget);
        cmb_mmpersec->setObjectName(QString::fromUtf8("cmb_mmpersec"));
        cmb_mmpersec->setEnabled(false);

        gridLayout->addWidget(cmb_mmpersec, 5, 1, 1, 1);

        UART_output = new QTextEdit(centralWidget);
        UART_output->setObjectName(QString::fromUtf8("UART_output"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(UART_output->sizePolicy().hasHeightForWidth());
        UART_output->setSizePolicy(sizePolicy3);
        UART_output->setReadOnly(true);

        gridLayout->addWidget(UART_output, 7, 0, 1, 3);

        pushButton_DL_calibration = new QPushButton(centralWidget);
        pushButton_DL_calibration->setObjectName(QString::fromUtf8("pushButton_DL_calibration"));
        sizePolicy1.setHeightForWidth(pushButton_DL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_DL_calibration->setSizePolicy(sizePolicy1);
        pushButton_DL_calibration->setLayoutDirection(Qt::LeftToRight);
        pushButton_DL_calibration->setAutoFillBackground(false);
        pushButton_DL_calibration->setAutoRepeat(false);
        pushButton_DL_calibration->setAutoExclusive(false);
        pushButton_DL_calibration->setAutoDefault(false);

        gridLayout->addWidget(pushButton_DL_calibration, 1, 0, 1, 1);

        pushButton_UL_calibration = new QPushButton(centralWidget);
        pushButton_UL_calibration->setObjectName(QString::fromUtf8("pushButton_UL_calibration"));
        sizePolicy1.setHeightForWidth(pushButton_UL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_UL_calibration->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_UL_calibration, 3, 0, 1, 1);

        pushButton_clear_canvas = new QPushButton(centralWidget);
        pushButton_clear_canvas->setObjectName(QString::fromUtf8("pushButton_clear_canvas"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_clear_canvas->sizePolicy().hasHeightForWidth());
        pushButton_clear_canvas->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(pushButton_clear_canvas, 8, 10, 1, 1);

        pushButton_COM_connect = new QPushButton(centralWidget);
        pushButton_COM_connect->setObjectName(QString::fromUtf8("pushButton_COM_connect"));
        sizePolicy1.setHeightForWidth(pushButton_COM_connect->sizePolicy().hasHeightForWidth());
        pushButton_COM_connect->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_COM_connect, 0, 2, 1, 1);

        comboBox_port = new QComboBox(centralWidget);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));

        gridLayout->addWidget(comboBox_port, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 964, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        cmb_dynamic_ranges->setCurrentIndex(3);
        cmb_mmpersec->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton_dynamic_range_set->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\264\320\270\320\275\320\260\320\274\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pushButton_mmpersec_calibration->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\271 \320\262\320\270\320\261\321\200\320\276\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label_port->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_DL_multimeter->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", 0, QApplication::UnicodeUTF8));
        pushButton_UL_multimeter->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", 0, QApplication::UnicodeUTF8));
        pushButton_UL_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_DL_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        lineEdit_DL_value->setText(QApplication::translate("MainWindow", "113", 0, QApplication::UnicodeUTF8));
        lineEdit_UL_value->setText(QApplication::translate("MainWindow", "1576", 0, QApplication::UnicodeUTF8));
        cmb_dynamic_ranges->clear();
        cmb_dynamic_ranges->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "02", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "04", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "08", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
        );
        pushButton_dynamic_range_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_calibrate_device->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\321\202\321\207\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pushButton_mmpersec_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        cmb_mmpersec->clear();
        cmb_mmpersec->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "020", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "050", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "200", 0, QApplication::UnicodeUTF8)
        );
        pushButton_DL_calibration->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\320\270\320\266\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", 0, QApplication::UnicodeUTF8));
        pushButton_UL_calibration->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\262\320\265\321\200\321\205\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", 0, QApplication::UnicodeUTF8));
        pushButton_clear_canvas->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pushButton_COM_connect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
