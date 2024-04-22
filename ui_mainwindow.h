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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *pushButton_mmpersec_write;
    QPushButton *pushButton_calibrate_device;
    QPushButton *pushButton_default_settings_set;
    QPushButton *pushButton_thermointercept_write;
    QComboBox *cmb_constant_component;
    QFrame *line_3;
    QPushButton *menuClear;
    QLabel *label_port;
    QLineEdit *lineEdit_thermo_lowTemperature_constant;
    QPushButton *pushButton_thermointercept_set;
    QPushButton *pushButton_thermohelp;
    QLineEdit *lineEdit_thermointercept;
    QPushButton *pushButton_dynamic_range_set;
    QPushButton *pushButton_dynamic_range_write;
    QPushButton *pushButton_measuring_axis_set;
    QComboBox *comboBox_port;
    QSpinBox *lineEdit_DL_value;
    QTextEdit *UART_output;
    QLineEdit *lineEdit_mmpersec_value;
    QPushButton *pushButton_UL_write;
    QPushButton *pushButton_mmpersec_calibration;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *canvas_A;
    QCustomPlot *canvas_V;
    QLineEdit *lineEdit_thermoslope;
    QPushButton *pushButton_constant_value_set;
    QComboBox *cmb_axis_measuring;
    QPushButton *pushButton_thermo_lowTemperature_constant_write;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_RMS_V_y;
    QLineEdit *lineEdit_RMS_T;
    QLineEdit *lineEdit_current_buffer;
    QLabel *label_2;
    QLineEdit *lineEdit_z_mg;
    QLineEdit *lineEdit_RMS_V_x;
    QLineEdit *lineEdit_RMS_A_x;
    QLineEdit *lineEdit_RMS_A_z;
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_16;
    QLineEdit *lineEdit_RMS_A_y;
    QLabel *label;
    QLabel *label_7;
    QLineEdit *lineEdit_samples_reserve;
    QLabel *label_4;
    QLabel *label_9;
    QLineEdit *lineEdit_RMS_V_xyz;
    QLabel *label_12;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *lineEdit_RMS_A_xyz;
    QLineEdit *lineEdit_RMS_V_z;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_y_mg;
    QLabel *label_10;
    QLineEdit *lineEdit_x_mg;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_8;
    QLabel *label_14;
    QLineEdit *lineEdit_constant_value;
    QPushButton *pushButton_axis_write;
    QPushButton *pushButton_UL_multimeter;
    QPushButton *pushButton_DL_multimeter;
    QPushButton *pushButton_settings;
    QSpinBox *lineEdit_UL_value;
    QPushButton *pushButton_UL_calibration;
    QPushButton *pushButton_DL_calibration;
    QPushButton *pushButton_userCommand;
    QPushButton *pushButton_thermoslope_set;
    QPushButton *pushButton_thermo_lowTemperature_constant_set;
    QCheckBox *checkBox_need_plot;
    QPushButton *pushButton_DL_write;
    QFrame *line;
    QPushButton *pushButton_constant_component_set;
    QPushButton *pushButton_measuring_axis_write;
    QPushButton *pushButton_constant_value_write;
    QPushButton *pushButton_constant_component_write;
    QPushButton *pushButton_COM_connect;
    QPushButton *pushButton_thermoslope_write;
    QComboBox *cmb_axis;
    QPushButton *pushButton_manual;
    QComboBox *cmb_dynamic_ranges;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1215, 698);
        MainWindow->setDocumentMode(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_mmpersec_write = new QPushButton(centralWidget);
        pushButton_mmpersec_write->setObjectName(QString::fromUtf8("pushButton_mmpersec_write"));
        pushButton_mmpersec_write->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_mmpersec_write->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_write->setSizePolicy(sizePolicy);
        pushButton_mmpersec_write->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_mmpersec_write, 4, 3, 1, 2);

        pushButton_calibrate_device = new QPushButton(centralWidget);
        pushButton_calibrate_device->setObjectName(QString::fromUtf8("pushButton_calibrate_device"));
        pushButton_calibrate_device->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_calibrate_device->sizePolicy().hasHeightForWidth());
        pushButton_calibrate_device->setSizePolicy(sizePolicy1);
        pushButton_calibrate_device->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(pushButton_calibrate_device, 14, 0, 1, 2);

        pushButton_default_settings_set = new QPushButton(centralWidget);
        pushButton_default_settings_set->setObjectName(QString::fromUtf8("pushButton_default_settings_set"));
        pushButton_default_settings_set->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_default_settings_set->sizePolicy().hasHeightForWidth());
        pushButton_default_settings_set->setSizePolicy(sizePolicy);
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

        pushButton_thermointercept_write = new QPushButton(centralWidget);
        pushButton_thermointercept_write->setObjectName(QString::fromUtf8("pushButton_thermointercept_write"));
        pushButton_thermointercept_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_thermointercept_write->sizePolicy().hasHeightForWidth());
        pushButton_thermointercept_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_thermointercept_write, 10, 3, 1, 2);

        cmb_constant_component = new QComboBox(centralWidget);
        cmb_constant_component->addItem(QString());
        cmb_constant_component->addItem(QString());
        cmb_constant_component->setObjectName(QString::fromUtf8("cmb_constant_component"));
        sizePolicy1.setHeightForWidth(cmb_constant_component->sizePolicy().hasHeightForWidth());
        cmb_constant_component->setSizePolicy(sizePolicy1);
        cmb_constant_component->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(cmb_constant_component, 7, 2, 1, 1);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 15, 0, 1, 5);

        menuClear = new QPushButton(centralWidget);
        menuClear->setObjectName(QString::fromUtf8("menuClear"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(menuClear->sizePolicy().hasHeightForWidth());
        menuClear->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(menuClear, 19, 8, 1, 1);

        label_port = new QLabel(centralWidget);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_port->sizePolicy().hasHeightForWidth());
        label_port->setSizePolicy(sizePolicy3);
        label_port->setMaximumSize(QSize(16777215, 16777215));
        label_port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_port, 0, 0, 1, 1);

        lineEdit_thermo_lowTemperature_constant = new QLineEdit(centralWidget);
        lineEdit_thermo_lowTemperature_constant->setObjectName(QString::fromUtf8("lineEdit_thermo_lowTemperature_constant"));
        lineEdit_thermo_lowTemperature_constant->setEnabled(true);
        sizePolicy1.setHeightForWidth(lineEdit_thermo_lowTemperature_constant->sizePolicy().hasHeightForWidth());
        lineEdit_thermo_lowTemperature_constant->setSizePolicy(sizePolicy1);
        lineEdit_thermo_lowTemperature_constant->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_thermo_lowTemperature_constant->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_thermo_lowTemperature_constant, 11, 2, 1, 1);

        pushButton_thermointercept_set = new QPushButton(centralWidget);
        pushButton_thermointercept_set->setObjectName(QString::fromUtf8("pushButton_thermointercept_set"));
        pushButton_thermointercept_set->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_thermointercept_set->sizePolicy().hasHeightForWidth());
        pushButton_thermointercept_set->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_thermointercept_set, 10, 0, 1, 2);

        pushButton_thermohelp = new QPushButton(centralWidget);
        pushButton_thermohelp->setObjectName(QString::fromUtf8("pushButton_thermohelp"));

        gridLayout->addWidget(pushButton_thermohelp, 19, 7, 1, 1);

        lineEdit_thermointercept = new QLineEdit(centralWidget);
        lineEdit_thermointercept->setObjectName(QString::fromUtf8("lineEdit_thermointercept"));
        lineEdit_thermointercept->setEnabled(true);
        sizePolicy1.setHeightForWidth(lineEdit_thermointercept->sizePolicy().hasHeightForWidth());
        lineEdit_thermointercept->setSizePolicy(sizePolicy1);
        lineEdit_thermointercept->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_thermointercept->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_thermointercept, 10, 2, 1, 1);

        pushButton_dynamic_range_set = new QPushButton(centralWidget);
        pushButton_dynamic_range_set->setObjectName(QString::fromUtf8("pushButton_dynamic_range_set"));
        pushButton_dynamic_range_set->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_dynamic_range_set->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_set->setSizePolicy(sizePolicy1);
        pushButton_dynamic_range_set->setMinimumSize(QSize(0, 0));
        pushButton_dynamic_range_set->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(pushButton_dynamic_range_set, 5, 0, 1, 2);

        pushButton_dynamic_range_write = new QPushButton(centralWidget);
        pushButton_dynamic_range_write->setObjectName(QString::fromUtf8("pushButton_dynamic_range_write"));
        pushButton_dynamic_range_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_dynamic_range_write->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_range_write->setSizePolicy(sizePolicy);
        pushButton_dynamic_range_write->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_dynamic_range_write, 5, 3, 1, 2);

        pushButton_measuring_axis_set = new QPushButton(centralWidget);
        pushButton_measuring_axis_set->setObjectName(QString::fromUtf8("pushButton_measuring_axis_set"));
        sizePolicy1.setHeightForWidth(pushButton_measuring_axis_set->sizePolicy().hasHeightForWidth());
        pushButton_measuring_axis_set->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_measuring_axis_set, 6, 0, 1, 2);

        comboBox_port = new QComboBox(centralWidget);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));
        comboBox_port->setMinimumSize(QSize(240, 0));
        comboBox_port->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(comboBox_port, 0, 1, 1, 2);

        lineEdit_DL_value = new QSpinBox(centralWidget);
        lineEdit_DL_value->setObjectName(QString::fromUtf8("lineEdit_DL_value"));
        lineEdit_DL_value->setEnabled(true);
        lineEdit_DL_value->setAlignment(Qt::AlignCenter);
        lineEdit_DL_value->setMaximum(9999);
        lineEdit_DL_value->setValue(0);

        gridLayout->addWidget(lineEdit_DL_value, 2, 2, 1, 1);

        UART_output = new QTextEdit(centralWidget);
        UART_output->setObjectName(QString::fromUtf8("UART_output"));
        sizePolicy3.setHeightForWidth(UART_output->sizePolicy().hasHeightForWidth());
        UART_output->setSizePolicy(sizePolicy3);
        UART_output->setMinimumSize(QSize(0, 0));
        UART_output->setReadOnly(true);

        gridLayout->addWidget(UART_output, 18, 5, 1, 5);

        lineEdit_mmpersec_value = new QLineEdit(centralWidget);
        lineEdit_mmpersec_value->setObjectName(QString::fromUtf8("lineEdit_mmpersec_value"));
        sizePolicy1.setHeightForWidth(lineEdit_mmpersec_value->sizePolicy().hasHeightForWidth());
        lineEdit_mmpersec_value->setSizePolicy(sizePolicy1);
        lineEdit_mmpersec_value->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_mmpersec_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_mmpersec_value, 4, 2, 1, 1);

        pushButton_UL_write = new QPushButton(centralWidget);
        pushButton_UL_write->setObjectName(QString::fromUtf8("pushButton_UL_write"));
        pushButton_UL_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_UL_write->sizePolicy().hasHeightForWidth());
        pushButton_UL_write->setSizePolicy(sizePolicy);
        pushButton_UL_write->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_UL_write, 3, 4, 1, 1);

        pushButton_mmpersec_calibration = new QPushButton(centralWidget);
        pushButton_mmpersec_calibration->setObjectName(QString::fromUtf8("pushButton_mmpersec_calibration"));
        pushButton_mmpersec_calibration->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_mmpersec_calibration->sizePolicy().hasHeightForWidth());
        pushButton_mmpersec_calibration->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_mmpersec_calibration, 4, 0, 1, 2);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 13, 0, 1, 5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        canvas_A = new QCustomPlot(centralWidget);
        canvas_A->setObjectName(QString::fromUtf8("canvas_A"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(canvas_A->sizePolicy().hasHeightForWidth());
        canvas_A->setSizePolicy(sizePolicy4);
        canvas_A->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(canvas_A);

        canvas_V = new QCustomPlot(centralWidget);
        canvas_V->setObjectName(QString::fromUtf8("canvas_V"));
        sizePolicy4.setHeightForWidth(canvas_V->sizePolicy().hasHeightForWidth());
        canvas_V->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(canvas_V);


        gridLayout->addLayout(horizontalLayout, 0, 5, 18, 5);

        lineEdit_thermoslope = new QLineEdit(centralWidget);
        lineEdit_thermoslope->setObjectName(QString::fromUtf8("lineEdit_thermoslope"));
        lineEdit_thermoslope->setEnabled(true);
        sizePolicy1.setHeightForWidth(lineEdit_thermoslope->sizePolicy().hasHeightForWidth());
        lineEdit_thermoslope->setSizePolicy(sizePolicy1);
        lineEdit_thermoslope->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_thermoslope->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_thermoslope, 9, 2, 1, 1);

        pushButton_constant_value_set = new QPushButton(centralWidget);
        pushButton_constant_value_set->setObjectName(QString::fromUtf8("pushButton_constant_value_set"));
        pushButton_constant_value_set->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_constant_value_set->sizePolicy().hasHeightForWidth());
        pushButton_constant_value_set->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_constant_value_set, 12, 0, 1, 2);

        cmb_axis_measuring = new QComboBox(centralWidget);
        cmb_axis_measuring->addItem(QString());
        cmb_axis_measuring->addItem(QString());
        cmb_axis_measuring->addItem(QString());
        cmb_axis_measuring->addItem(QString());
        cmb_axis_measuring->setObjectName(QString::fromUtf8("cmb_axis_measuring"));
        sizePolicy1.setHeightForWidth(cmb_axis_measuring->sizePolicy().hasHeightForWidth());
        cmb_axis_measuring->setSizePolicy(sizePolicy1);
        cmb_axis_measuring->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(cmb_axis_measuring, 6, 2, 1, 1);

        pushButton_thermo_lowTemperature_constant_write = new QPushButton(centralWidget);
        pushButton_thermo_lowTemperature_constant_write->setObjectName(QString::fromUtf8("pushButton_thermo_lowTemperature_constant_write"));
        pushButton_thermo_lowTemperature_constant_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_thermo_lowTemperature_constant_write->sizePolicy().hasHeightForWidth());
        pushButton_thermo_lowTemperature_constant_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_thermo_lowTemperature_constant_write, 11, 3, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_RMS_V_y = new QLineEdit(centralWidget);
        lineEdit_RMS_V_y->setObjectName(QString::fromUtf8("lineEdit_RMS_V_y"));
        lineEdit_RMS_V_y->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_V_y, 8, 2, 1, 1);

        lineEdit_RMS_T = new QLineEdit(centralWidget);
        lineEdit_RMS_T->setObjectName(QString::fromUtf8("lineEdit_RMS_T"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_RMS_T->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_T->setSizePolicy(sizePolicy5);
        lineEdit_RMS_T->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_RMS_T->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_T, 4, 3, 1, 1);

        lineEdit_current_buffer = new QLineEdit(centralWidget);
        lineEdit_current_buffer->setObjectName(QString::fromUtf8("lineEdit_current_buffer"));
        lineEdit_current_buffer->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_current_buffer, 4, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 6, 2, 1, 1);

        lineEdit_z_mg = new QLineEdit(centralWidget);
        lineEdit_z_mg->setObjectName(QString::fromUtf8("lineEdit_z_mg"));
        lineEdit_z_mg->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_z_mg->setAlignment(Qt::AlignCenter);
        lineEdit_z_mg->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_z_mg, 1, 3, 1, 1);

        lineEdit_RMS_V_x = new QLineEdit(centralWidget);
        lineEdit_RMS_V_x->setObjectName(QString::fromUtf8("lineEdit_RMS_V_x"));
        sizePolicy5.setHeightForWidth(lineEdit_RMS_V_x->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_V_x->setSizePolicy(sizePolicy5);
        lineEdit_RMS_V_x->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_RMS_V_x->setAlignment(Qt::AlignCenter);
        lineEdit_RMS_V_x->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_RMS_V_x, 7, 2, 1, 1);

        lineEdit_RMS_A_x = new QLineEdit(centralWidget);
        lineEdit_RMS_A_x->setObjectName(QString::fromUtf8("lineEdit_RMS_A_x"));
        sizePolicy5.setHeightForWidth(lineEdit_RMS_A_x->sizePolicy().hasHeightForWidth());
        lineEdit_RMS_A_x->setSizePolicy(sizePolicy5);
        lineEdit_RMS_A_x->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_RMS_A_x->setAlignment(Qt::AlignCenter);
        lineEdit_RMS_A_x->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_RMS_A_x, 7, 1, 1, 1);

        lineEdit_RMS_A_z = new QLineEdit(centralWidget);
        lineEdit_RMS_A_z->setObjectName(QString::fromUtf8("lineEdit_RMS_A_z"));
        lineEdit_RMS_A_z->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_A_z, 9, 1, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 3, 3, 1, 1);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        gridLayout_2->addWidget(label_16, 10, 0, 1, 1);

        lineEdit_RMS_A_y = new QLineEdit(centralWidget);
        lineEdit_RMS_A_y->setObjectName(QString::fromUtf8("lineEdit_RMS_A_y"));
        lineEdit_RMS_A_y->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_A_y, 8, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 6, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);

        lineEdit_samples_reserve = new QLineEdit(centralWidget);
        lineEdit_samples_reserve->setObjectName(QString::fromUtf8("lineEdit_samples_reserve"));
        lineEdit_samples_reserve->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_samples_reserve, 4, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 0, 3, 1, 1);

        lineEdit_RMS_V_xyz = new QLineEdit(centralWidget);
        lineEdit_RMS_V_xyz->setObjectName(QString::fromUtf8("lineEdit_RMS_V_xyz"));
        lineEdit_RMS_V_xyz->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_V_xyz, 10, 2, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 5, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3, 7, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 16777215));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_RMS_A_xyz = new QLineEdit(centralWidget);
        lineEdit_RMS_A_xyz->setObjectName(QString::fromUtf8("lineEdit_RMS_A_xyz"));
        lineEdit_RMS_A_xyz->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_A_xyz, 10, 1, 1, 1);

        lineEdit_RMS_V_z = new QLineEdit(centralWidget);
        lineEdit_RMS_V_z->setObjectName(QString::fromUtf8("lineEdit_RMS_V_z"));
        lineEdit_RMS_V_z->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_RMS_V_z, 9, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 11, 0, 1, 1);

        lineEdit_y_mg = new QLineEdit(centralWidget);
        lineEdit_y_mg->setObjectName(QString::fromUtf8("lineEdit_y_mg"));
        lineEdit_y_mg->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_y_mg->setAlignment(Qt::AlignCenter);
        lineEdit_y_mg->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_y_mg, 1, 2, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 3, 2, 1, 1);

        lineEdit_x_mg = new QLineEdit(centralWidget);
        lineEdit_x_mg->setObjectName(QString::fromUtf8("lineEdit_x_mg"));
        lineEdit_x_mg->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_x_mg->setAlignment(Qt::AlignCenter);
        lineEdit_x_mg->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_x_mg, 1, 1, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 3, 1, 1, 1);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        gridLayout_2->addWidget(label_15, 9, 0, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        gridLayout_2->addWidget(label_14, 8, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 16, 0, 4, 5);

        lineEdit_constant_value = new QLineEdit(centralWidget);
        lineEdit_constant_value->setObjectName(QString::fromUtf8("lineEdit_constant_value"));
        lineEdit_constant_value->setEnabled(true);
        sizePolicy1.setHeightForWidth(lineEdit_constant_value->sizePolicy().hasHeightForWidth());
        lineEdit_constant_value->setSizePolicy(sizePolicy1);
        lineEdit_constant_value->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_constant_value->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_constant_value, 12, 2, 1, 1);

        pushButton_axis_write = new QPushButton(centralWidget);
        pushButton_axis_write->setObjectName(QString::fromUtf8("pushButton_axis_write"));
        sizePolicy.setHeightForWidth(pushButton_axis_write->sizePolicy().hasHeightForWidth());
        pushButton_axis_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_axis_write, 14, 3, 1, 2);

        pushButton_UL_multimeter = new QPushButton(centralWidget);
        pushButton_UL_multimeter->setObjectName(QString::fromUtf8("pushButton_UL_multimeter"));
        pushButton_UL_multimeter->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_UL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_UL_multimeter->setSizePolicy(sizePolicy);
        pushButton_UL_multimeter->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_UL_multimeter, 3, 3, 1, 1);

        pushButton_DL_multimeter = new QPushButton(centralWidget);
        pushButton_DL_multimeter->setObjectName(QString::fromUtf8("pushButton_DL_multimeter"));
        pushButton_DL_multimeter->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_DL_multimeter->sizePolicy().hasHeightForWidth());
        pushButton_DL_multimeter->setSizePolicy(sizePolicy);
        pushButton_DL_multimeter->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_DL_multimeter, 2, 3, 1, 1);

        pushButton_settings = new QPushButton(centralWidget);
        pushButton_settings->setObjectName(QString::fromUtf8("pushButton_settings"));
        sizePolicy2.setHeightForWidth(pushButton_settings->sizePolicy().hasHeightForWidth());
        pushButton_settings->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton_settings, 19, 9, 1, 1);

        lineEdit_UL_value = new QSpinBox(centralWidget);
        lineEdit_UL_value->setObjectName(QString::fromUtf8("lineEdit_UL_value"));
        lineEdit_UL_value->setEnabled(true);
        lineEdit_UL_value->setAlignment(Qt::AlignCenter);
        lineEdit_UL_value->setMaximum(9999);
        lineEdit_UL_value->setValue(0);

        gridLayout->addWidget(lineEdit_UL_value, 3, 2, 1, 1);

        pushButton_UL_calibration = new QPushButton(centralWidget);
        pushButton_UL_calibration->setObjectName(QString::fromUtf8("pushButton_UL_calibration"));
        pushButton_UL_calibration->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_UL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_UL_calibration->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_UL_calibration, 3, 0, 1, 2);

        pushButton_DL_calibration = new QPushButton(centralWidget);
        pushButton_DL_calibration->setObjectName(QString::fromUtf8("pushButton_DL_calibration"));
        pushButton_DL_calibration->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_DL_calibration->sizePolicy().hasHeightForWidth());
        pushButton_DL_calibration->setSizePolicy(sizePolicy1);
        pushButton_DL_calibration->setLayoutDirection(Qt::LeftToRight);
        pushButton_DL_calibration->setAutoFillBackground(false);
        pushButton_DL_calibration->setAutoRepeat(false);
        pushButton_DL_calibration->setAutoExclusive(false);
        pushButton_DL_calibration->setAutoDefault(false);

        gridLayout->addWidget(pushButton_DL_calibration, 2, 0, 1, 2);

        pushButton_userCommand = new QPushButton(centralWidget);
        pushButton_userCommand->setObjectName(QString::fromUtf8("pushButton_userCommand"));
        sizePolicy1.setHeightForWidth(pushButton_userCommand->sizePolicy().hasHeightForWidth());
        pushButton_userCommand->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_userCommand, 1, 0, 1, 3);

        pushButton_thermoslope_set = new QPushButton(centralWidget);
        pushButton_thermoslope_set->setObjectName(QString::fromUtf8("pushButton_thermoslope_set"));
        pushButton_thermoslope_set->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_thermoslope_set->sizePolicy().hasHeightForWidth());
        pushButton_thermoslope_set->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_thermoslope_set, 9, 0, 1, 2);

        pushButton_thermo_lowTemperature_constant_set = new QPushButton(centralWidget);
        pushButton_thermo_lowTemperature_constant_set->setObjectName(QString::fromUtf8("pushButton_thermo_lowTemperature_constant_set"));
        pushButton_thermo_lowTemperature_constant_set->setEnabled(true);
        sizePolicy1.setHeightForWidth(pushButton_thermo_lowTemperature_constant_set->sizePolicy().hasHeightForWidth());
        pushButton_thermo_lowTemperature_constant_set->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_thermo_lowTemperature_constant_set, 11, 0, 1, 2);

        checkBox_need_plot = new QCheckBox(centralWidget);
        checkBox_need_plot->setObjectName(QString::fromUtf8("checkBox_need_plot"));
        checkBox_need_plot->setChecked(true);

        gridLayout->addWidget(checkBox_need_plot, 19, 5, 1, 1);

        pushButton_DL_write = new QPushButton(centralWidget);
        pushButton_DL_write->setObjectName(QString::fromUtf8("pushButton_DL_write"));
        pushButton_DL_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_DL_write->sizePolicy().hasHeightForWidth());
        pushButton_DL_write->setSizePolicy(sizePolicy);
        pushButton_DL_write->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_DL_write, 2, 4, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 8, 0, 1, 5);

        pushButton_constant_component_set = new QPushButton(centralWidget);
        pushButton_constant_component_set->setObjectName(QString::fromUtf8("pushButton_constant_component_set"));
        sizePolicy1.setHeightForWidth(pushButton_constant_component_set->sizePolicy().hasHeightForWidth());
        pushButton_constant_component_set->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_constant_component_set, 7, 0, 1, 2);

        pushButton_measuring_axis_write = new QPushButton(centralWidget);
        pushButton_measuring_axis_write->setObjectName(QString::fromUtf8("pushButton_measuring_axis_write"));
        sizePolicy.setHeightForWidth(pushButton_measuring_axis_write->sizePolicy().hasHeightForWidth());
        pushButton_measuring_axis_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_measuring_axis_write, 6, 3, 1, 2);

        pushButton_constant_value_write = new QPushButton(centralWidget);
        pushButton_constant_value_write->setObjectName(QString::fromUtf8("pushButton_constant_value_write"));
        pushButton_constant_value_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_constant_value_write->sizePolicy().hasHeightForWidth());
        pushButton_constant_value_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_constant_value_write, 12, 3, 1, 2);

        pushButton_constant_component_write = new QPushButton(centralWidget);
        pushButton_constant_component_write->setObjectName(QString::fromUtf8("pushButton_constant_component_write"));
        sizePolicy.setHeightForWidth(pushButton_constant_component_write->sizePolicy().hasHeightForWidth());
        pushButton_constant_component_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_constant_component_write, 7, 3, 1, 2);

        pushButton_COM_connect = new QPushButton(centralWidget);
        pushButton_COM_connect->setObjectName(QString::fromUtf8("pushButton_COM_connect"));
        sizePolicy.setHeightForWidth(pushButton_COM_connect->sizePolicy().hasHeightForWidth());
        pushButton_COM_connect->setSizePolicy(sizePolicy);
        pushButton_COM_connect->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_COM_connect, 0, 3, 1, 2);

        pushButton_thermoslope_write = new QPushButton(centralWidget);
        pushButton_thermoslope_write->setObjectName(QString::fromUtf8("pushButton_thermoslope_write"));
        pushButton_thermoslope_write->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_thermoslope_write->sizePolicy().hasHeightForWidth());
        pushButton_thermoslope_write->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_thermoslope_write, 9, 3, 1, 2);

        cmb_axis = new QComboBox(centralWidget);
        cmb_axis->addItem(QString());
        cmb_axis->addItem(QString());
        cmb_axis->addItem(QString());
        cmb_axis->addItem(QString());
        cmb_axis->setObjectName(QString::fromUtf8("cmb_axis"));
        sizePolicy1.setHeightForWidth(cmb_axis->sizePolicy().hasHeightForWidth());
        cmb_axis->setSizePolicy(sizePolicy1);
        cmb_axis->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(cmb_axis, 14, 2, 1, 1);

        pushButton_manual = new QPushButton(centralWidget);
        pushButton_manual->setObjectName(QString::fromUtf8("pushButton_manual"));
        sizePolicy2.setHeightForWidth(pushButton_manual->sizePolicy().hasHeightForWidth());
        pushButton_manual->setSizePolicy(sizePolicy2);
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

        gridLayout->addWidget(pushButton_manual, 19, 6, 1, 1);

        cmb_dynamic_ranges = new QComboBox(centralWidget);
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->addItem(QString());
        cmb_dynamic_ranges->setObjectName(QString::fromUtf8("cmb_dynamic_ranges"));
        cmb_dynamic_ranges->setEnabled(true);
        sizePolicy1.setHeightForWidth(cmb_dynamic_ranges->sizePolicy().hasHeightForWidth());
        cmb_dynamic_ranges->setSizePolicy(sizePolicy1);
        cmb_dynamic_ranges->setMaximumSize(QSize(16777215, 16777215));
        cmb_dynamic_ranges->setLayoutDirection(Qt::LeftToRight);
        cmb_dynamic_ranges->setInsertPolicy(QComboBox::InsertAtBottom);
        cmb_dynamic_ranges->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(cmb_dynamic_ranges, 5, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        cmb_constant_component->setCurrentIndex(-1);
        cmb_axis_measuring->setCurrentIndex(-1);
        cmb_axis->setCurrentIndex(-1);
        cmb_dynamic_ranges->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\222\320\22417-\320\241\320\265\321\200\320\262\320\270\321\201", nullptr));
        pushButton_mmpersec_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_calibrate_device->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\321\202\321\207\320\270\320\272", nullptr));
        pushButton_default_settings_set->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\264\320\276 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\321\205", nullptr));
        pushButton_thermointercept_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        cmb_constant_component->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\276\321\202\320\275\320\270\320\274\320\260\321\202\321\214", nullptr));
        cmb_constant_component->setItemText(1, QCoreApplication::translate("MainWindow", "\320\236\321\202\320\275\320\270\320\274\320\260\321\202\321\214", nullptr));

        menuClear->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_port->setText(QCoreApplication::translate("MainWindow", "COM-\320\237\320\276\321\200\321\202", nullptr));
        lineEdit_thermo_lowTemperature_constant->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_thermointercept_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\201\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \321\202\320\265\321\200\320\274\320\276\320\277\321\200\321\217\320\274\320\276\320\271", nullptr));
        pushButton_thermohelp->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260 \320\277\320\276 \321\202\320\265\321\200\320\274\320\276\320\272\320\276\320\274\320\277\320\265\320\275\321\201\320\260\321\206\320\270\320\270", nullptr));
        lineEdit_thermointercept->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_dynamic_range_set->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\264\320\270\320\275\320\260\320\274\320\270\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\260", nullptr));
        pushButton_dynamic_range_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_measuring_axis_set->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\270\320\267\320\274\320\265\321\200\321\217\320\265\320\274\320\276\320\271 \320\276\321\201\320\270 \320\264\320\273\321\217 \320\242\320\237", nullptr));
        lineEdit_mmpersec_value->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_UL_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_mmpersec_calibration->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\271 \320\262\320\270\320\261\321\200\320\276\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", nullptr));
        lineEdit_thermoslope->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_constant_value_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\277\320\276\321\201\321\202\320\276\321\217\320\275\320\275\320\276\320\271 \320\262\320\270\320\261\321\200\320\276\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", nullptr));
        cmb_axis_measuring->setItemText(0, QCoreApplication::translate("MainWindow", "xyz", nullptr));
        cmb_axis_measuring->setItemText(1, QCoreApplication::translate("MainWindow", "x", nullptr));
        cmb_axis_measuring->setItemText(2, QCoreApplication::translate("MainWindow", "y", nullptr));
        cmb_axis_measuring->setItemText(3, QCoreApplication::translate("MainWindow", "z", nullptr));

        pushButton_thermo_lowTemperature_constant_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "V (\320\274\320\274/\321\201)", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "t (\302\260C)", nullptr));
        label_13->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 XYZ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\220 (\320\274/\321\201\302\262)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "x (mg)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\320\277\320\276\320\274\320\276\320\263\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "z (mg)", nullptr));
        label_12->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 X", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\260\321\201 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\261\321\203\321\204\320\265\321\200", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 Z", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "y (mg)", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 Y", nullptr));
        lineEdit_constant_value->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_axis_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_UL_multimeter->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", nullptr));
        pushButton_DL_multimeter->setText(QCoreApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", nullptr));
        pushButton_settings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\201\320\265\321\200\320\262\320\270\321\201\320\260...", nullptr));
        pushButton_UL_calibration->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\262\320\265\321\200\321\205\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", nullptr));
        pushButton_DL_calibration->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\320\270\320\266\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", nullptr));
        pushButton_userCommand->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\260\321\217 \320\272\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
        pushButton_thermoslope_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\275\320\260\320\272\320\273\320\276\320\275\320\260 \321\202\320\265\321\200\320\274\320\276\320\277\321\200\321\217\320\274\320\276\320\271", nullptr));
        pushButton_thermo_lowTemperature_constant_set->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\272\320\276\320\275\321\201\321\202\320\260\320\275\321\202\321\213 (\320\277\321\200\320\270 t < -50 \302\260C)", nullptr));
        checkBox_need_plot->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\260 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        pushButton_DL_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_constant_component_set->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\277\320\276\321\201\321\202\320\276\321\217\320\275\320\275\320\276\320\271 \321\201\320\276\321\201\321\202\320\260\320\262\320\273\321\217\321\216\321\211\320\265\320\271", nullptr));
        pushButton_measuring_axis_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_constant_value_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_constant_component_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        pushButton_COM_connect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        pushButton_thermoslope_write->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        cmb_axis->setItemText(0, QCoreApplication::translate("MainWindow", "xyz", nullptr));
        cmb_axis->setItemText(1, QCoreApplication::translate("MainWindow", "x", nullptr));
        cmb_axis->setItemText(2, QCoreApplication::translate("MainWindow", "y", nullptr));
        cmb_axis->setItemText(3, QCoreApplication::translate("MainWindow", "z", nullptr));

        pushButton_manual->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217 \320\277\320\276 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\265 \320\222\320\22417", nullptr));
        cmb_dynamic_ranges->setItemText(0, QCoreApplication::translate("MainWindow", "2g", nullptr));
        cmb_dynamic_ranges->setItemText(1, QCoreApplication::translate("MainWindow", "4g", nullptr));
        cmb_dynamic_ranges->setItemText(2, QCoreApplication::translate("MainWindow", "8g", nullptr));
        cmb_dynamic_ranges->setItemText(3, QCoreApplication::translate("MainWindow", "16g", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
