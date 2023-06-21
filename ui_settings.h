/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Tue 20. Jun 18:17:33 2023
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_bufferSize;
    QLineEdit *lineEdit_bufferSize;
    QLabel *label_messageCode;
    QLineEdit *lineEdit_messageCode;
    QLabel *label_UART_speed;
    QComboBox *comboBox_UART_speed;
    QLabel *label_UART_dataBits;
    QComboBox *comboBox_UART_dataBits;
    QLabel *label_UAR_parity;
    QComboBox *comboBox_UART_parity;
    QLabel *label_UART_stopBits;
    QComboBox *comboBox_UART_stopBits;
    QLabel *label_UART_flowControl;
    QComboBox *comboBox_UART_flowControl;
    QLabel *label_aboutProgram;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 250);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_bufferSize = new QLabel(Dialog);
        label_bufferSize->setObjectName(QString::fromUtf8("label_bufferSize"));

        gridLayout->addWidget(label_bufferSize, 0, 0, 1, 1);

        lineEdit_bufferSize = new QLineEdit(Dialog);
        lineEdit_bufferSize->setObjectName(QString::fromUtf8("lineEdit_bufferSize"));

        gridLayout->addWidget(lineEdit_bufferSize, 0, 1, 1, 1);

        label_messageCode = new QLabel(Dialog);
        label_messageCode->setObjectName(QString::fromUtf8("label_messageCode"));

        gridLayout->addWidget(label_messageCode, 1, 0, 1, 1);

        lineEdit_messageCode = new QLineEdit(Dialog);
        lineEdit_messageCode->setObjectName(QString::fromUtf8("lineEdit_messageCode"));

        gridLayout->addWidget(lineEdit_messageCode, 1, 1, 1, 1);

        label_UART_speed = new QLabel(Dialog);
        label_UART_speed->setObjectName(QString::fromUtf8("label_UART_speed"));

        gridLayout->addWidget(label_UART_speed, 2, 0, 1, 1);

        comboBox_UART_speed = new QComboBox(Dialog);
        comboBox_UART_speed->setObjectName(QString::fromUtf8("comboBox_UART_speed"));

        gridLayout->addWidget(comboBox_UART_speed, 2, 1, 1, 1);

        label_UART_dataBits = new QLabel(Dialog);
        label_UART_dataBits->setObjectName(QString::fromUtf8("label_UART_dataBits"));

        gridLayout->addWidget(label_UART_dataBits, 3, 0, 1, 1);

        comboBox_UART_dataBits = new QComboBox(Dialog);
        comboBox_UART_dataBits->setObjectName(QString::fromUtf8("comboBox_UART_dataBits"));

        gridLayout->addWidget(comboBox_UART_dataBits, 3, 1, 1, 1);

        label_UAR_parity = new QLabel(Dialog);
        label_UAR_parity->setObjectName(QString::fromUtf8("label_UAR_parity"));

        gridLayout->addWidget(label_UAR_parity, 4, 0, 1, 1);

        comboBox_UART_parity = new QComboBox(Dialog);
        comboBox_UART_parity->setObjectName(QString::fromUtf8("comboBox_UART_parity"));

        gridLayout->addWidget(comboBox_UART_parity, 4, 1, 1, 1);

        label_UART_stopBits = new QLabel(Dialog);
        label_UART_stopBits->setObjectName(QString::fromUtf8("label_UART_stopBits"));

        gridLayout->addWidget(label_UART_stopBits, 5, 0, 1, 1);

        comboBox_UART_stopBits = new QComboBox(Dialog);
        comboBox_UART_stopBits->setObjectName(QString::fromUtf8("comboBox_UART_stopBits"));

        gridLayout->addWidget(comboBox_UART_stopBits, 5, 1, 1, 1);

        label_UART_flowControl = new QLabel(Dialog);
        label_UART_flowControl->setObjectName(QString::fromUtf8("label_UART_flowControl"));

        gridLayout->addWidget(label_UART_flowControl, 6, 0, 1, 1);

        comboBox_UART_flowControl = new QComboBox(Dialog);
        comboBox_UART_flowControl->setObjectName(QString::fromUtf8("comboBox_UART_flowControl"));

        gridLayout->addWidget(comboBox_UART_flowControl, 6, 1, 1, 1);

        label_aboutProgram = new QLabel(Dialog);
        label_aboutProgram->setObjectName(QString::fromUtf8("label_aboutProgram"));

        gridLayout->addWidget(label_aboutProgram, 7, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 1, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_bufferSize->setText(QApplication::translate("Dialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\276\320\273\321\214\321\206\320\265\320\262\320\276\320\263\320\276 \320\261\321\203\321\204\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
        lineEdit_bufferSize->setText(QApplication::translate("Dialog", "32", 0, QApplication::UnicodeUTF8));
        label_messageCode->setText(QApplication::translate("Dialog", "\320\232\320\276\320\264 \320\262 \320\272\320\276\320\275\321\206\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        lineEdit_messageCode->setText(QApplication::translate("Dialog", "***", 0, QApplication::UnicodeUTF8));
        label_UART_speed->setText(QApplication::translate("Dialog", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\276\321\200\321\202\320\260", 0, QApplication::UnicodeUTF8));
        comboBox_UART_speed->clear();
        comboBox_UART_speed->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "1200", 0, QApplication::UnicodeUTF8)
        );
        label_UART_dataBits->setText(QApplication::translate("Dialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\261\320\270\321\202\320\276\320\262 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
        comboBox_UART_dataBits->clear();
        comboBox_UART_dataBits->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "5", 0, QApplication::UnicodeUTF8)
        );
        label_UAR_parity->setText(QApplication::translate("Dialog", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \321\207\320\265\321\202\320\275\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        comboBox_UART_parity->clear();
        comboBox_UART_parity->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\320\235\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\320\247\320\265\321\202\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\320\235\320\265\321\207\320\265\321\202\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\320\237\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\320\234\320\260\321\200\320\272\320\270\321\200\320\276\320\262\320\276\321\207\320\275\321\213\320\271", 0, QApplication::UnicodeUTF8)
        );
        label_UART_stopBits->setText(QApplication::translate("Dialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\320\276\320\277-\320\261\320\270\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        comboBox_UART_stopBits->clear();
        comboBox_UART_stopBits->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "1.5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "2", 0, QApplication::UnicodeUTF8)
        );
        label_UART_flowControl->setText(QApplication::translate("Dialog", "\320\220\320\277\320\277\320\260\321\200\320\260\321\202\320\275\320\276\320\265 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\321\202\320\276\320\272\320\276\320\274", 0, QApplication::UnicodeUTF8));
        comboBox_UART_flowControl->clear();
        comboBox_UART_flowControl->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\320\235\320\265\321\202", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "\320\224\320\260", 0, QApplication::UnicodeUTF8)
        );
        label_aboutProgram->setText(QApplication::translate("Dialog", "\320\234\320\270\320\272\321\200\320\276\320\275\320\270\320\272\321\201, \320\236\320\274\321\201\320\272 2023. \320\222\320\265\321\200\321\201\320\270\321\217 2.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
