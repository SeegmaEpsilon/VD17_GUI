/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 31. Oct 18:31:46 2022
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
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_port;
    QComboBox *comboBox_port;
    QPushButton *pushButton_COM_connect;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_DL_calibration;
    QLineEdit *lineEdit_DL_value;
    QPushButton *pushButton_DL_write;
    QPushButton *pushButton_DL_multimeter;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_mmpersec_calibration;
    QComboBox *cmb_mmpersec;
    QPushButton *pushButton_mmpersec_write;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_UL_calibration;
    QLineEdit *lineEdit_UL_value;
    QPushButton *pushButton_UL_write;
    QPushButton *pushButton_UL_multimeter;
    QFrame *line;
    QFrame *line_2;
    QTextEdit *UART_output;
    QPushButton *pushButton_calibrate_device;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(399, 424);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_port = new QLabel(centralWidget);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_port->sizePolicy().hasHeightForWidth());
        label_port->setSizePolicy(sizePolicy);
        label_port->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_port);

        comboBox_port = new QComboBox(centralWidget);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));

        horizontalLayout->addWidget(comboBox_port);

        pushButton_COM_connect = new QPushButton(centralWidget);
        pushButton_COM_connect->setObjectName(QString::fromUtf8("pushButton_COM_connect"));

        horizontalLayout->addWidget(pushButton_COM_connect);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_DL_calibration = new QPushButton(centralWidget);
        pushButton_DL_calibration->setObjectName(QString::fromUtf8("pushButton_DL_calibration"));
        pushButton_DL_calibration->setLayoutDirection(Qt::LeftToRight);
        pushButton_DL_calibration->setAutoFillBackground(false);
        pushButton_DL_calibration->setAutoRepeat(false);
        pushButton_DL_calibration->setAutoExclusive(false);
        pushButton_DL_calibration->setAutoDefault(false);

        horizontalLayout_2->addWidget(pushButton_DL_calibration);

        lineEdit_DL_value = new QLineEdit(centralWidget);
        lineEdit_DL_value->setObjectName(QString::fromUtf8("lineEdit_DL_value"));
        lineEdit_DL_value->setEnabled(false);
        lineEdit_DL_value->setMaxLength(3);
        lineEdit_DL_value->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit_DL_value);

        pushButton_DL_write = new QPushButton(centralWidget);
        pushButton_DL_write->setObjectName(QString::fromUtf8("pushButton_DL_write"));
        pushButton_DL_write->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_DL_write);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_DL_multimeter = new QPushButton(centralWidget);
        pushButton_DL_multimeter->setObjectName(QString::fromUtf8("pushButton_DL_multimeter"));
        pushButton_DL_multimeter->setEnabled(false);

        verticalLayout->addWidget(pushButton_DL_multimeter);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_mmpersec_calibration = new QPushButton(centralWidget);
        pushButton_mmpersec_calibration->setObjectName(QString::fromUtf8("pushButton_mmpersec_calibration"));
        pushButton_mmpersec_calibration->setEnabled(true);

        horizontalLayout_4->addWidget(pushButton_mmpersec_calibration);

        cmb_mmpersec = new QComboBox(centralWidget);
        cmb_mmpersec->setObjectName(QString::fromUtf8("cmb_mmpersec"));
        cmb_mmpersec->setEnabled(false);

        horizontalLayout_4->addWidget(cmb_mmpersec);

        pushButton_mmpersec_write = new QPushButton(centralWidget);
        pushButton_mmpersec_write->setObjectName(QString::fromUtf8("pushButton_mmpersec_write"));
        pushButton_mmpersec_write->setEnabled(false);

        horizontalLayout_4->addWidget(pushButton_mmpersec_write);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_UL_calibration = new QPushButton(centralWidget);
        pushButton_UL_calibration->setObjectName(QString::fromUtf8("pushButton_UL_calibration"));

        horizontalLayout_3->addWidget(pushButton_UL_calibration);

        lineEdit_UL_value = new QLineEdit(centralWidget);
        lineEdit_UL_value->setObjectName(QString::fromUtf8("lineEdit_UL_value"));
        lineEdit_UL_value->setEnabled(false);
        lineEdit_UL_value->setMaxLength(4);
        lineEdit_UL_value->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_UL_value);

        pushButton_UL_write = new QPushButton(centralWidget);
        pushButton_UL_write->setObjectName(QString::fromUtf8("pushButton_UL_write"));
        pushButton_UL_write->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_UL_write);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pushButton_UL_multimeter = new QPushButton(centralWidget);
        pushButton_UL_multimeter->setObjectName(QString::fromUtf8("pushButton_UL_multimeter"));
        pushButton_UL_multimeter->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_UL_multimeter);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(2);
        line->setMidLineWidth(0);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setLineWidth(2);
        line_2->setMidLineWidth(0);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 4, 0, 1, 1);

        UART_output = new QTextEdit(centralWidget);
        UART_output->setObjectName(QString::fromUtf8("UART_output"));
        UART_output->setReadOnly(true);

        gridLayout->addWidget(UART_output, 6, 0, 1, 1);

        pushButton_calibrate_device = new QPushButton(centralWidget);
        pushButton_calibrate_device->setObjectName(QString::fromUtf8("pushButton_calibrate_device"));
        pushButton_calibrate_device->setEnabled(true);

        gridLayout->addWidget(pushButton_calibrate_device, 7, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 399, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_port->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        pushButton_COM_connect->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        pushButton_DL_calibration->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\275\320\270\320\266\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", 0, QApplication::UnicodeUTF8));
        lineEdit_DL_value->setText(QApplication::translate("MainWindow", "113", 0, QApplication::UnicodeUTF8));
        pushButton_DL_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_DL_multimeter->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", 0, QApplication::UnicodeUTF8));
        pushButton_mmpersec_calibration->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\271 \320\262\320\270\320\261\321\200\320\276\321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_mmpersec_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_UL_calibration->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \320\262\320\265\321\200\321\205\320\275\320\265\320\263\320\276 \320\277\321\200\320\265\320\264\320\265\320\273\320\260 \320\242\320\237", 0, QApplication::UnicodeUTF8));
        lineEdit_UL_value->setText(QApplication::translate("MainWindow", "1576", 0, QApplication::UnicodeUTF8));
        pushButton_UL_write->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_UL_multimeter->setText(QApplication::translate("MainWindow", "\320\234\321\203\320\273\321\214\321\202\320\270\320\274\320\265\321\202\321\200", 0, QApplication::UnicodeUTF8));
        pushButton_calibrate_device->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\321\202\321\207\320\270\320\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
