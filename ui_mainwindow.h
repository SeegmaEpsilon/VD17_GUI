/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_constant_value_write;
    QPushButton *pushButton_thermo_lowTemperature_constant_write;
    QPushButton *pushButton_thermo_lowTemperature_constant_set;
    QPushButton *pushButton_mmpersec_write;
    QCheckBox *checkBox_need_plot;
    QPushButton *pushButton_DL_calibration;
    QLineEdit *lineEdit_thermointercept;
    QPushButton *pushButton_manual;
    QPushButton *pushButton_dynamic_range_write;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_average_V;
    QLineEdit *lineEdit_RMS_V;
    QLineEdit *lineEdit_RMS_T;
    QLineEdit *lineEdit_average_A;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit_RMS_A;
    QLineEdit *lineEdit_average_T;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *pushButton_calibrate_device;
    QPushButton *pushButton_mmpersec_calibration;
    QPushButton *pushButton_DL_multimeter;
    QPushButton *pushButton_userCommand;
    QLabel *label_port;
    QPushButton *pushButton_default_settings_set;
    QPushButton *pushButton_thermohelp;
    QPushButton *pushButton_DL_write;
    QPushButton *pushButton_UL_multimeter;
    QComboBox *comboBox_port;
    QLineEdit *lineEdit_thermo_lowTemperature_constant;
    QLineEdit *lineEdit_constant_value;
    QSpinBox *lineEdit_UL_value;
    QCustomPlot *canvas;
    QPushButton *pushButton_thermoslope_set;
    QLineEdit *lineEdit_mmpersec_value;
    QPushButton *pushButton_thermointercept_write;
    QPushButton *pushButton_COM_connect;
    QSpinBox *lineEdit_DL_value;
    QPushButton *pushButton_UL_calibration;
    QFrame *line;
    QPushButton *menuClear;
    QPushButton *pushButton_dynamic_range_set;
    QTextEdit *UART_output;
    QLineEdit *lineEdit_thermoslope;
    QPushButton *pushButton_constant_value_set;
    QPushButton *pushButton_settings;
    QPushButton *pushButton_UL_write;
    QComboBox *cmb_dynamic_ranges;
    QPushButton *pushButton_thermoslope_write;
    QPushButton *pushButton_thermointercept_set;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1137, 700);
        MainWindow->setDocumentMode(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_constant_value_write = new QPushButton(centralWidget);
        pushButton_constant_value_write->setObjectName(QString::fromUtf8("pushButton_constant_value_write"));
        pushButton_constant_value_write->setEnabled(true);

        gridLayout->addWidget(pushButton_constant_value_write, 10, 3, 1, 2);

        pushButton_thermo_lowTemperature_constant_write = new QPushButton(centralWidget);
        pushButton_thermo_lowTemperature_constant_write->setObjectName(QString::fromUtf8("pushButton_thermo_lowTemperature_constant_write"));
        pushButton_thermo_lowTemperature_constant_write->setEnabled(true);

        gridLayout->addWidget(pushButton_thermo_lowTemperature_constant_write, 9, 3, 1, 2);

        pushButton_thermo_lowTemperature_constant_set = new QPushButton(centralWidget);
        pushButton_thermo_lowTemperature_constant_set->setObjectName(QString::fromUtf8("pushButton_thermo_lowTemperature_constant_set"));
        pushButton_thermo_lowTemperature_constant_set->setEnabled(true);

        gridLayout->addWidget(pushButton_thermo_lowTemperature_constant_set, 9, 0, 1, 2);

        pushButton_mmpersec_write = new QPushButton(centralWidget);
        pushButton_mmpersec_write->setObjectName(QString::fromUtf8("pushButton_mmpersec_write"));
        pushButton_mmpersec_write->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_mmpersec_write->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_write->setSizePolicy(sizePolicy);
        pushButton_mmpersec_write->setMaximumSize(QSize(166, 21));

        gridLayout->addWidget(pushButton_mmpersec_write, 5, 3, 1, 2);

        checkBox_need_plot = new QCheckBox(centralWidget);
        checkBox_need_plot->setObjectName(QString::fromUtf8("checkBox_need_plot"));
        checkBox_need_plot->setChecked(true);

        gridLayout->addWidget(checkBox_need_plot, 17, 5, 1, 1);

        pushButton_DL_calibration = new QPushButton(centralWidget);
        pushButton_DL_calibration->setObjectName(QString::fromUtf8("pushButton_DL_calibration"));
        pushButton_DL_calibration->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_DL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_DL_calibration->setSizePolicy(sizePolicy);
        pushButton_DL_calibration->setLayoutDirection(Qt::LeftToRight);
        pushButton_DL_calibration->setAutoFillBackground(false);
        pushButton_DL_calibration->setAutoRepeat(false);
        pushButton_DL_calibration->setAutoExclusive(false);
        pushButton_DL_calibration->setAutoDefault(false);

        gridLayout->addWidget(pushButton_DL_calibration, 2, 0, 1, 2);

        lineEdit_thermointercept = new QLineEdit(centralWidget);
        lineEdit_thermointercept->setObjectName(QString::fromUtf8("lineEdit_thermointercept"));
        lineEdit_thermointercept->setEnabled(true);
        lineEdit_thermointercept->setMaximumSize(QSize(60, 16777215));
        lineEdit_thermointercept->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_thermointercept, 8, 2, 1, 1);

        pushButton_manual = new QPushButton(centralWidget);
        pushButton_manual->setObjectName(QString::fromUtf8("pushButton_manual"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_manual->sizePolicy().hasHeightForWidth());
        pushButton_manual->setSizePolicy(sizePolicy1);
        pushButton_manual->setMinimumSize(QSize(166, 21));
        pushButton_manual->setMaximumSize(QSize(166, 21));
        pushButton_manual->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  border: 1px solid gray;\n"
"  background-color:rgba(0, 0, 255, 20);\n"
"  border-radius: 10px;\n"
"} \n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(0, 0, 255, 30);\n"
"   border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(pushButton_manual, 17, 6, 1, 1);

        pushButton_dynamic_range_write = new QPushButton(centralWidget);
        pushButton_dynamic_range_write->setObjectName(QString::fromUtf8("pushButton_dynamic_range_write"));
        pushButton_dynamic_range_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_dynamic_range_write->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_write->setSizePolicy(sizePolicy);
        pushButton_dynamic_range_write->setMaximumSize(QSize(166, 21));

        gridLayout->addWidget(pushButton_dynamic_range_write, 4, 3, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(6);
        lineEdit_average_V = new QLineEdit(centralWidget);
        lineEdit_average_V->setObjectName(QString::fromUtf8("lineEdit_average_V"));
        sizePolicy.setHeightForWidth(lineEdit_average_V->sizePolicy().hasHeightForWidth());
        lineEdit_average_V->setSizePolicy(sizePolicy);
        lineEdit_average_V->setMaximumSize(QSize(80, 166666));
        lineEdit_average_V->setAlignment(Qt::AlignCenter);
        lineEdit_average_V->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_average_V, 2, 2, 1, 1);

        lineEdit_RMS_V = new QLineEdit(centralWidget);
        lineEdit_RMS_V->setObjectName(QString::fromUtf8("lineEdit_RMS_V"));
        sizePolicy.setHeightForWidth(lineEdit_RMS_V->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_V->setSizePolicy(sizePolicy);
        lineEdit_RMS_V->setMaximumSize(QSize(80, 22));
        lineEdit_RMS_V->setAlignment(Qt::AlignCenter);
        lineEdit_RMS_V->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_RMS_V, 1, 2, 1, 1);

        lineEdit_RMS_T = new QLineEdit(centralWidget);
        lineEdit_RMS_T->setObjectName(QString::fromUtf8("lineEdit_RMS_T"));
        sizePolicy.setHeightForWidth(lineEdit_RMS_T->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_T->setSizePolicy(sizePolicy);
        lineEdit_RMS_T->setMaximumSize(QSize(80, 22));
        lineEdit_RMS_T->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_T, 1, 3, 1, 1);

        lineEdit_average_A = new QLineEdit(centralWidget);
        lineEdit_average_A->setObjectName(QString::fromUtf8("lineEdit_average_A"));
        sizePolicy.setHeightForWidth(lineEdit_average_A->sizePolicy().hasHeightForWidth());
        lineEdit_average_A->setSizePolicy(sizePolicy);
        lineEdit_average_A->setMaximumSize(QSize(80, 166666));
        lineEdit_average_A->setAlignment(Qt::AlignCenter);
        lineEdit_average_A->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_average_A, 2, 1, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        lineEdit_RMS_A = new QLineEdit(centralWidget);
        lineEdit_RMS_A->setObjectName(QString::fromUtf8("lineEdit_RMS_A"));
        sizePolicy.setHeightForWidth(lineEdit_RMS_A->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_A->setSizePolicy(sizePolicy);
        lineEdit_RMS_A->setMaximumSize(QSize(80, 22));
        lineEdit_RMS_A->setAlignment(Qt::AlignCenter);
        lineEdit_RMS_A->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_RMS_A, 1, 1, 1, 1);

        lineEdit_average_T = new QLineEdit(centralWidget);
        lineEdit_average_T->setObjectName(QString::fromUtf8("lineEdit_average_T"));
        lineEdit_average_T->setMinimumSize(QSize(0, 0));
        lineEdit_average_T->setMaximumSize(QSize(80, 16777215));
        lineEdit_average_T->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_average_T, 2, 3, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 0, 3, 1, 1);

        pushButton_calibrate_device = new QPushButton(centralWidget);
        pushButton_calibrate_device->setObjectName(QString::fromUtf8("pushButton_calibrate_device"));
        pushButton_calibrate_device->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_calibrate_device->sizePolicy().hasHeightForWidth());
        pushButton_calibrate_device->setSizePolicy(sizePolicy);
        pushButton_calibrate_device->setMinimumSize(QSize(0, 46));

        gridLayout_2->addWidget(pushButton_calibrate_device, 1, 4, 2, 1);


        gridLayout->addLayout(gridLayout_2, 11, 0, 1, 5);

        pushButton_mmpersec_calibration = new QPushButton(centralWidget);
        pushButton_mmpersec_calibration->setObjectName(QString::fromUtf8("pushButton_mmpersec_calibration"));
        pushButton_mmpersec_calibration->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_mmpersec_calibration->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_calibration->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_mmpersec_calibration, 5, 0, 1, 2);

        pushButton_DL_multimeter = new QPushButton(centralWidget);
        pushButton_DL_multimeter->setObjectName(QString::fromUtf8("pushButton_DL_multimeter"));
        pushButton_DL_multimeter->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_DL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_DL_multimeter->setSizePolicy(sizePolicy);
        pushButton_DL_multimeter->setMaximumSize(QSize(80, 21));

        gridLayout->addWidget(pushButton_DL_multimeter, 2, 3, 1, 1);

        pushButton_userCommand = new QPushButton(centralWidget);
        pushButton_userCommand->setObjectName(QString::fromUtf8("pushButton_userCommand"));
        sizePolicy.setHeightForWidth(pushButton_userCommand->sizePolicy().hasHeightForWidth());
        pushButton_userCommand->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_userCommand, 1, 0, 1, 3);

        label_port = new QLabel(centralWidget);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        sizePolicy2.setHeightForWidth(label_port->sizePolicy().hasHeightForWidth());
        label_port->setSizePolicy(sizePolicy2);
        label_port->setMaximumSize(QSize(60, 16777215));
        label_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_port, 0, 0, 1, 1);

        pushButton_default_settings_set = new QPushButton(centralWidget);
        pushButton_default_settings_set->setObjectName(QString::fromUtf8("pushButton_default_settings_set"));
        pushButton_default_settings_set->setEnabled(true);
        pushButton_default_settings_set->setMinimumSize(QSize(0, 20));
        pushButton_default_settings_set->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"  border: 1px solid gray;\n"
"  background-color:rgba(122, 0, 0, 20);\n"
"  border-radius:1px;\n"
"} \n"
"QPushButton:hover\n"
"{\n"
"   background-color:rgba(255, 0, 0, 30);\n"
"   border: 1px solid gray;\n"
"}"));

        gridLayout->addWidget(pushButton_default_settings_set, 1, 3, 1, 2);

        pushButton_thermohelp = new QPushButton(centralWidget);
        pushButton_thermohelp->setObjectName(QString::fromUtf8("pushButton_thermohelp"));

        gridLayout->addWidget(pushButton_thermohelp, 17, 7, 1, 1);

        pushButton_DL_write = new QPushButton(centralWidget);
        pushButton_DL_write->setObjectName(QString::fromUtf8("pushButton_DL_write"));
        pushButton_DL_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_DL_write->sizePolicy().hasHeightForWidth());
        pushButton_DL_write->setSizePolicy(sizePolicy);
        pushButton_DL_write->setMaximumSize(QSize(80, 21));

        gridLayout->addWidget(pushButton_DL_write, 2, 4, 1, 1);

        pushButton_UL_multimeter = new QPushButton(centralWidget);
        pushButton_UL_multimeter->setObjectName(QString::fromUtf8("pushButton_UL_multimeter"));
        pushButton_UL_multimeter->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_UL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_UL_multimeter->setSizePolicy(sizePolicy);
        pushButton_UL_multimeter->setMaximumSize(QSize(80, 21));

        gridLayout->addWidget(pushButton_UL_multimeter, 3, 3, 1, 1);

        comboBox_port = new QComboBox(centralWidget);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));

        gridLayout->addWidget(comboBox_port, 0, 1, 1, 2);

        lineEdit_thermo_lowTemperature_constant = new QLineEdit(centralWidget);
        lineEdit_thermo_lowTemperature_constant->setObjectName(QString::fromUtf8("lineEdit_thermo_lowTemperature_constant"));
        lineEdit_thermo_lowTemperature_constant->setEnabled(true);
        lineEdit_thermo_lowTemperature_constant->setMaximumSize(QSize(60, 16777215));
        lineEdit_thermo_lowTemperature_constant->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_thermo_lowTemperature_constant, 9, 2, 1, 1);

        lineEdit_constant_value = new QLineEdit(centralWidget);
        lineEdit_constant_value->setObjectName(QString::fromUtf8("lineEdit_constant_value"));
        lineEdit_constant_value->setEnabled(true);
        lineEdit_constant_value->setMaximumSize(QSize(60, 16777215));
        lineEdit_constant_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_constant_value, 10, 2, 1, 1);

        lineEdit_UL_value = new QSpinBox(centralWidget);
        lineEdit_UL_value->setObjectName(QString::fromUtf8("lineEdit_UL_value"));
        lineEdit_UL_value->setEnabled(true);
        lineEdit_UL_value->setAlignment(Qt::AlignCenter);
        lineEdit_UL_value->setMaximum(9999);
        lineEdit_UL_value->setValue(0);

        gridLayout->addWidget(lineEdit_UL_value, 3, 2, 1, 1);

        canvas = new QCustomPlot(centralWidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(canvas->sizePolicy().hasHeightForWidth());
        canvas->setSizePolicy(sizePolicy3);
        canvas->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(canvas, 0, 5, 17, 5);

        pushButton_thermoslope_set = new QPushButton(centralWidget);
        pushButton_thermoslope_set->setObjectName(QString::fromUtf8("pushButton_thermoslope_set"));
        pushButton_thermoslope_set->setEnabled(true);

        gridLayout->addWidget(pushButton_thermoslope_set, 7, 0, 1, 2);

        lineEdit_mmpersec_value = new QLineEdit(centralWidget);
        lineEdit_mmpersec_value->setObjectName(QString::fromUtf8("lineEdit_mmpersec_value"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_mmpersec_value->sizePolicy().hasHeightForWidth());
        lineEdit_mmpersec_value->setSizePolicy(sizePolicy4);
        lineEdit_mmpersec_value->setMaximumSize(QSize(60, 16777215));
        lineEdit_mmpersec_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_mmpersec_value, 5, 2, 1, 1);

        pushButton_thermointercept_write = new QPushButton(centralWidget);
        pushButton_thermointercept_write->setObjectName(QString::fromUtf8("pushButton_thermointercept_write"));
        pushButton_thermointercept_write->setEnabled(true);

        gridLayout->addWidget(pushButton_thermointercept_write, 8, 3, 1, 2);

        pushButton_COM_connect = new QPushButton(centralWidget);
        pushButton_COM_connect->setObjectName(QString::fromUtf8("pushButton_COM_connect"));
        sizePolicy.setHeightForWidth(pushButton_COM_connect->sizePolicy().hasHeightForWidth());
        pushButton_COM_connect->setSizePolicy(sizePolicy);
        pushButton_COM_connect->setMaximumSize(QSize(166, 21));

        gridLayout->addWidget(pushButton_COM_connect, 0, 3, 1, 2);

        lineEdit_DL_value = new QSpinBox(centralWidget);
        lineEdit_DL_value->setObjectName(QString::fromUtf8("lineEdit_DL_value"));
        lineEdit_DL_value->setEnabled(true);
        lineEdit_DL_value->setAlignment(Qt::AlignCenter);
        lineEdit_DL_value->setMaximum(9999);
        lineEdit_DL_value->setValue(0);

        gridLayout->addWidget(lineEdit_DL_value, 2, 2, 1, 1);

        pushButton_UL_calibration = new QPushButton(centralWidget);
        pushButton_UL_calibration->setObjectName(QString::fromUtf8("pushButton_UL_calibration"));
        pushButton_UL_calibration->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_UL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_UL_calibration->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_UL_calibration, 3, 0, 1, 2);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 6, 0, 1, 5);

        menuClear = new QPushButton(centralWidget);
        menuClear->setObjectName(QString::fromUtf8("menuClear"));
        sizePolicy1.setHeightForWidth(menuClear->sizePolicy().hasHeightForWidth());
        menuClear->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(menuClear, 17, 8, 1, 1);

        pushButton_dynamic_range_set = new QPushButton(centralWidget);
        pushButton_dynamic_range_set->setObjectName(QString::fromUtf8("pushButton_dynamic_range_set"));
        pushButton_dynamic_range_set->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_dynamic_range_set->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_set->setSizePolicy(sizePolicy);
        pushButton_dynamic_range_set->setMinimumSize(QSize(215, 0));
        pushButton_dynamic_range_set->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(pushButton_dynamic_range_set, 4, 0, 1, 2);

        UART_output = new QTextEdit(centralWidget);
        UART_output->setObjectName(QString::fromUtf8("UART_output"));
        sizePolicy2.setHeightForWidth(UART_output->sizePolicy().hasHeightForWidth());
        UART_output->setSizePolicy(sizePolicy2);
        UART_output->setMinimumSize(QSize(0, 0));
        UART_output->setReadOnly(true);

        gridLayout->addWidget(UART_output, 12, 0, 6, 5);

        lineEdit_thermoslope = new QLineEdit(centralWidget);
        lineEdit_thermoslope->setObjectName(QString::fromUtf8("lineEdit_thermoslope"));
        lineEdit_thermoslope->setEnabled(true);
        lineEdit_thermoslope->setMaximumSize(QSize(60, 16777215));
        lineEdit_thermoslope->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_thermoslope, 7, 2, 1, 1);

        pushButton_constant_value_set = new QPushButton(centralWidget);
        pushButton_constant_value_set->setObjectName(QString::fromUtf8("pushButton_constant_value_set"));
        pushButton_constant_value_set->setEnabled(true);

        gridLayout->addWidget(pushButton_constant_value_set, 10, 0, 1, 2);

        pushButton_settings = new QPushButton(centralWidget);
        pushButton_settings->setObjectName(QString::fromUtf8("pushButton_settings"));
        sizePolicy1.setHeightForWidth(pushButton_settings->sizePolicy().hasHeightForWidth());
        pushButton_settings->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_settings, 17, 9, 1, 1);

        pushButton_UL_write = new QPushButton(centralWidget);
        pushButton_UL_write->setObjectName(QString::fromUtf8("pushButton_UL_write"));
        pushButton_UL_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_UL_write->sizePolicy().hasHeightForWidth());
        pushButton_UL_write->setSizePolicy(sizePolicy);
        pushButton_UL_write->setMaximumSize(QSize(80, 21));

        gridLayout->addWidget(pushButton_UL_write, 3, 4, 1, 1);

        cmb_dynamic_ranges = new QComboBox(centralWidget);
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->setObjectName(QString::fromUtf8("cmb_dynamic_ranges"));
        cmb_dynamic_ranges->setEnabled(true);
        cmb_dynamic_ranges->setLayoutDirection(Qt::LeftToRight);
        cmb_dynamic_ranges->setInsertPolicy(QComboBox::InsertAtBottom);
        cmb_dynamic_ranges->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(cmb_dynamic_ranges, 4, 2, 1, 1);

        pushButton_thermoslope_write = new QPushButton(centralWidget);
        pushButton_thermoslope_write->setObjectName(QString::fromUtf8("pushButton_thermoslope_write"));
        pushButton_thermoslope_write->setEnabled(true);

        gridLayout->addWidget(pushButton_thermoslope_write, 7, 3, 1, 2);

        pushButton_thermointercept_set = new QPushButton(centralWidget);
        pushButton_thermointercept_set->setObjectName(QString::fromUtf8("pushButton_thermointercept_set"));
        pushButton_thermointercept_set->setEnabled(true);

        gridLayout->addWidget(pushButton_thermointercept_set, 8, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        cmb_dynamic_ranges->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\222\320\22417-\320\241\320\265\321\200\320\262\320\270\321\201", nullptr));
        pushButton_constant_value_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_thermo_lowTemperature_constant_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_thermo_lowTemperature_constant_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\272\320\276\320\275\321\201\321\202\320\260\320\275\321\202\321\213 (\320\277\321\200\320\270 t < -50 \302\260C)", nullptr));
        pushButton_mmpersec_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        checkBox_need_plot->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        pushButton_DL_calibration->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\320\270\320\266\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", nullptr));
        lineEdit_thermointercept->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_manual->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217 \320\277\320\276 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\265 \320\222\320\22417", nullptr));
        pushButton_dynamic_range_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\220 (\320\274/\321\201\302\262)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "V (\320\274\320\274/\321\201)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "t (\302\260C)", nullptr));
        pushButton_calibrate_device->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\321\202\321\207\320\270\320\272", nullptr));
        pushButton_mmpersec_calibration->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\271 \320\262\320\270\320\261\321\200\320\276\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", nullptr));
        pushButton_DL_multimeter->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", nullptr));
        pushButton_userCommand->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\260\321\217 \320\272\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
        label_port->setText(QCoreApplication::translate("MainWindow", "COM-\320\237\320\276\321\200\321\202", nullptr));
        pushButton_default_settings_set->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\264\320\276 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\321\205", nullptr));
        pushButton_thermohelp->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260 \320\277\320\276 \321\202\320\265\321\200\320\274\320\276\320\272\320\276\320\274\320\277\320\265\320\275\321\201\320\260\321\206\320\270\320\270", nullptr));
        pushButton_DL_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_UL_multimeter->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", nullptr));
        lineEdit_thermo_lowTemperature_constant->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        lineEdit_constant_value->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_thermoslope_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\275\320\260\320\272\320\273\320\276\320\275\320\260 \321\202\320\265\321\200\320\274\320\276\320\277\321\200\321\217\320\274\320\276\320\271", nullptr));
        lineEdit_mmpersec_value->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_thermointercept_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_COM_connect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        pushButton_UL_calibration->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\262\320\265\321\200\321\205\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", nullptr));
        menuClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton_dynamic_range_set->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\264\320\270\320\275\320\260\320\274\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\260", nullptr));
        lineEdit_thermoslope->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_constant_value_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\277\320\276\321\201\321\202\320\276\321\217\320\275\320\275\320\276\320\271 \320\262\320\270\320\261\321\200\320\276\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", nullptr));
        pushButton_settings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\201\320\265\321\200\320\262\320\270\321\201\320\260...", nullptr));
        pushButton_UL_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        cmb_dynamic_ranges->setItemText(0, QCoreApplication::translate("MainWindow", "2g", nullptr));
        cmb_dynamic_ranges->setItemText(1, QCoreApplication::translate("MainWindow", "4g", nullptr));
        cmb_dynamic_ranges->setItemText(2, QCoreApplication::translate("MainWindow", "8g", nullptr));
        cmb_dynamic_ranges->setItemText(3, QCoreApplication::translate("MainWindow", "16g", nullptr));

        pushButton_thermoslope_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_thermointercept_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\201\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \321\202\320\265\321\200\320\274\320\276\320\277\321\200\321\217\320\274\320\276\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
