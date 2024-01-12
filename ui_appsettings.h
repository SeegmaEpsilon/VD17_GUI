/********************************************************************************
** Form generated from reading UI file 'appsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPSETTINGS_H
#define UI_APPSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_appSettings
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_messageCode;
    QLineEdit *lineEdit_bufferSize;
    QLabel *label_UART_speed;
    QLabel *label_bufferSize;
    QComboBox *comboBox_UART_speed;
    QLabel *label_messageCode;
    QLabel *label_UART_dataBits;
    QLabel *label_UART_stopBits;
    QLabel *label_UAR_parity;
    QComboBox *comboBox_UART_dataBits;
    QComboBox *comboBox_UART_parity;
    QDialogButtonBox *buttonBox;
    QLabel *label_UART_flowControl;
    QComboBox *comboBox_UART_flowControl;
    QPushButton *pushButton_defaultSettings;
    QComboBox *comboBox_UART_stopBits;
    QLabel *label;

    void setupUi(QDialog *appSettings)
    {
        if (appSettings->objectName().isEmpty())
            appSettings->setObjectName(QString::fromUtf8("appSettings"));
        appSettings->resize(328, 261);
        gridLayout = new QGridLayout(appSettings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_messageCode = new QLineEdit(appSettings);
        lineEdit_messageCode->setObjectName(QString::fromUtf8("lineEdit_messageCode"));

        gridLayout->addWidget(lineEdit_messageCode, 2, 1, 1, 1);

        lineEdit_bufferSize = new QLineEdit(appSettings);
        lineEdit_bufferSize->setObjectName(QString::fromUtf8("lineEdit_bufferSize"));

        gridLayout->addWidget(lineEdit_bufferSize, 1, 1, 1, 1);

        label_UART_speed = new QLabel(appSettings);
        label_UART_speed->setObjectName(QString::fromUtf8("label_UART_speed"));

        gridLayout->addWidget(label_UART_speed, 3, 0, 1, 1);

        label_bufferSize = new QLabel(appSettings);
        label_bufferSize->setObjectName(QString::fromUtf8("label_bufferSize"));

        gridLayout->addWidget(label_bufferSize, 1, 0, 1, 1);

        comboBox_UART_speed = new QComboBox(appSettings);
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->addItem(QString());
        comboBox_UART_speed->setObjectName(QString::fromUtf8("comboBox_UART_speed"));

        gridLayout->addWidget(comboBox_UART_speed, 3, 1, 1, 1);

        label_messageCode = new QLabel(appSettings);
        label_messageCode->setObjectName(QString::fromUtf8("label_messageCode"));

        gridLayout->addWidget(label_messageCode, 2, 0, 1, 1);

        label_UART_dataBits = new QLabel(appSettings);
        label_UART_dataBits->setObjectName(QString::fromUtf8("label_UART_dataBits"));

        gridLayout->addWidget(label_UART_dataBits, 4, 0, 1, 1);

        label_UART_stopBits = new QLabel(appSettings);
        label_UART_stopBits->setObjectName(QString::fromUtf8("label_UART_stopBits"));

        gridLayout->addWidget(label_UART_stopBits, 6, 0, 1, 1);

        label_UAR_parity = new QLabel(appSettings);
        label_UAR_parity->setObjectName(QString::fromUtf8("label_UAR_parity"));

        gridLayout->addWidget(label_UAR_parity, 5, 0, 1, 1);

        comboBox_UART_dataBits = new QComboBox(appSettings);
        comboBox_UART_dataBits->addItem(QString());
        comboBox_UART_dataBits->addItem(QString());
        comboBox_UART_dataBits->addItem(QString());
        comboBox_UART_dataBits->addItem(QString());
        comboBox_UART_dataBits->setObjectName(QString::fromUtf8("comboBox_UART_dataBits"));

        gridLayout->addWidget(comboBox_UART_dataBits, 4, 1, 1, 1);

        comboBox_UART_parity = new QComboBox(appSettings);
        comboBox_UART_parity->addItem(QString());
        comboBox_UART_parity->addItem(QString());
        comboBox_UART_parity->addItem(QString());
        comboBox_UART_parity->addItem(QString());
        comboBox_UART_parity->addItem(QString());
        comboBox_UART_parity->setObjectName(QString::fromUtf8("comboBox_UART_parity"));

        gridLayout->addWidget(comboBox_UART_parity, 5, 1, 1, 1);

        buttonBox = new QDialogButtonBox(appSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 1, 1, 1);

        label_UART_flowControl = new QLabel(appSettings);
        label_UART_flowControl->setObjectName(QString::fromUtf8("label_UART_flowControl"));

        gridLayout->addWidget(label_UART_flowControl, 7, 0, 1, 1);

        comboBox_UART_flowControl = new QComboBox(appSettings);
        comboBox_UART_flowControl->addItem(QString());
        comboBox_UART_flowControl->addItem(QString());
        comboBox_UART_flowControl->addItem(QString());
        comboBox_UART_flowControl->setObjectName(QString::fromUtf8("comboBox_UART_flowControl"));

        gridLayout->addWidget(comboBox_UART_flowControl, 7, 1, 1, 1);

        pushButton_defaultSettings = new QPushButton(appSettings);
        pushButton_defaultSettings->setObjectName(QString::fromUtf8("pushButton_defaultSettings"));

        gridLayout->addWidget(pushButton_defaultSettings, 8, 0, 1, 1);

        comboBox_UART_stopBits = new QComboBox(appSettings);
        comboBox_UART_stopBits->addItem(QString());
        comboBox_UART_stopBits->addItem(QString());
        comboBox_UART_stopBits->addItem(QString());
        comboBox_UART_stopBits->setObjectName(QString::fromUtf8("comboBox_UART_stopBits"));

        gridLayout->addWidget(comboBox_UART_stopBits, 6, 1, 1, 1);

        label = new QLabel(appSettings);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 20));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);


        retranslateUi(appSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), appSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), appSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(appSettings);
    } // setupUi

    void retranslateUi(QDialog *appSettings)
    {
        appSettings->setWindowTitle(QCoreApplication::translate("appSettings", "Dialog", nullptr));
        lineEdit_messageCode->setText(QCoreApplication::translate("appSettings", "***", nullptr));
        lineEdit_bufferSize->setText(QCoreApplication::translate("appSettings", "32", nullptr));
        label_UART_speed->setText(QCoreApplication::translate("appSettings", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\276\321\200\321\202\320\260", nullptr));
        label_bufferSize->setText(QCoreApplication::translate("appSettings", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\276\320\273\321\214\321\206\320\265\320\262\320\276\320\263\320\276 \320\261\321\203\321\204\320\265\321\200\320\260", nullptr));
        comboBox_UART_speed->setItemText(0, QCoreApplication::translate("appSettings", "115200", nullptr));
        comboBox_UART_speed->setItemText(1, QCoreApplication::translate("appSettings", "57600", nullptr));
        comboBox_UART_speed->setItemText(2, QCoreApplication::translate("appSettings", "38400", nullptr));
        comboBox_UART_speed->setItemText(3, QCoreApplication::translate("appSettings", "19200", nullptr));
        comboBox_UART_speed->setItemText(4, QCoreApplication::translate("appSettings", "9600", nullptr));
        comboBox_UART_speed->setItemText(5, QCoreApplication::translate("appSettings", "4800", nullptr));
        comboBox_UART_speed->setItemText(6, QCoreApplication::translate("appSettings", "2400", nullptr));
        comboBox_UART_speed->setItemText(7, QCoreApplication::translate("appSettings", "1200", nullptr));

        label_messageCode->setText(QCoreApplication::translate("appSettings", "\320\232\320\276\320\264 \320\262 \320\272\320\276\320\275\321\206\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_UART_dataBits->setText(QCoreApplication::translate("appSettings", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\261\320\270\321\202\320\276\320\262 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        label_UART_stopBits->setText(QCoreApplication::translate("appSettings", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\320\276\320\277-\320\261\320\270\321\202\320\276\320\262", nullptr));
        label_UAR_parity->setText(QCoreApplication::translate("appSettings", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \321\207\320\265\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
        comboBox_UART_dataBits->setItemText(0, QCoreApplication::translate("appSettings", "8", nullptr));
        comboBox_UART_dataBits->setItemText(1, QCoreApplication::translate("appSettings", "7", nullptr));
        comboBox_UART_dataBits->setItemText(2, QCoreApplication::translate("appSettings", "6", nullptr));
        comboBox_UART_dataBits->setItemText(3, QCoreApplication::translate("appSettings", "5", nullptr));

        comboBox_UART_parity->setItemText(0, QCoreApplication::translate("appSettings", "\320\235\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217", nullptr));
        comboBox_UART_parity->setItemText(1, QCoreApplication::translate("appSettings", "\320\247\320\265\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        comboBox_UART_parity->setItemText(2, QCoreApplication::translate("appSettings", "\320\235\320\265\321\207\320\265\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        comboBox_UART_parity->setItemText(3, QCoreApplication::translate("appSettings", "\320\237\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        comboBox_UART_parity->setItemText(4, QCoreApplication::translate("appSettings", "\320\234\320\260\321\200\320\272\320\270\321\200\320\276\320\262\320\276\321\207\320\275\321\213\320\271", nullptr));

        label_UART_flowControl->setText(QCoreApplication::translate("appSettings", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214 \320\277\320\276\321\202\320\276\320\272\320\260", nullptr));
        comboBox_UART_flowControl->setItemText(0, QCoreApplication::translate("appSettings", "\320\235\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217", nullptr));
        comboBox_UART_flowControl->setItemText(1, QCoreApplication::translate("appSettings", "\320\220\320\277\320\277\320\260\321\200\320\260\321\202\320\275\321\213\320\271", nullptr));
        comboBox_UART_flowControl->setItemText(2, QCoreApplication::translate("appSettings", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\321\213\320\271", nullptr));

        pushButton_defaultSettings->setText(QCoreApplication::translate("appSettings", "\320\237\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", nullptr));
        comboBox_UART_stopBits->setItemText(0, QCoreApplication::translate("appSettings", "1", nullptr));
        comboBox_UART_stopBits->setItemText(1, QCoreApplication::translate("appSettings", "1.5", nullptr));
        comboBox_UART_stopBits->setItemText(2, QCoreApplication::translate("appSettings", "2", nullptr));

        label->setText(QCoreApplication::translate("appSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\222\320\22417-\320\241\320\265\321\200\320\262\320\270\321\201 (\320\262\320\265\321\200\321\201\320\270\321\217 2.1)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class appSettings: public Ui_appSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPSETTINGS_H
