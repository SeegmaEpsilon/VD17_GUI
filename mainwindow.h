#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QTextCodec>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QApplication>
#include <QTextCodec>
#include <QElapsedTimer>
#include <qcustomplot.h>
#include <QFileDialog>
#include <QFile>
#include <QMenu>
#include <QSettings>
#include <appsettings.h>
#include <QInputDialog>

#include <support.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void setSettingsUI(appSettingsStruct settings);

private slots:
    bool serialPortCheckout();
    void processMessage(const QString & message);

    void writeToSerial(const char* command);
    void sendCommand(const char* commandBase, QLineEdit* lineEdit);
    void sendCommand(const char* commandBase, QComboBox* comboBox);
    void sendCommand(const char* commandBase, QSpinBox* spinBox);

    void handleAxis(const QString &message, QLineEdit *lineEdit, int graphRow, int graphColumn);
    void handleDebugMessage(const QString &message);
    void handleInitMessage(const QString &message);

    void printConsole(const QString& string);

    void on_pushButton_DL_write_clicked();
    void on_pushButton_UL_write_clicked();
    void on_pushButton_mmpersec_write_clicked();
    void on_pushButton_COM_connect_clicked();
    void on_pushButton_dynamic_range_write_clicked();
    void on_pushButton_thermoslope_write_clicked();
    void on_pushButton_thermointercept_write_clicked();
    void on_pushButton_constant_value_write_clicked();
    void on_pushButton_default_settings_set_clicked();
    void on_pushButton_get_config_clicked();
    void on_pushButton_thermo_lowTemperature_constant_write_clicked();
    void on_pushButton_measuring_axis_write_clicked();
    void on_pushButton_constant_component_write_clicked();
    void on_pushButton_measuring_parameter_write_clicked();
    void on_pushButton_axis_write_clicked();

    void on_pushButton_manual_clicked();
    void on_pushButton_settings_clicked();
    void on_pushButton_userCommand_clicked();
    void on_pushButton_thermohelp_clicked();

    void slotMouseMove(QMouseEvent * event);
    void slotMouseDoubleClick(QMouseEvent * event);
    void slotMousePress(QMouseEvent* event);
    void slotMouseRelease(QMouseEvent* event);

    void slotSavePlotPNG();
    void slotResetCanvas();
    void slotSaveDataFromPlot();

    void slotClearCanvas();
    void slotClearConsole();
    void slotClearAll();

    void initializeConnects();
    void initializeAppSettings();
    void initializeMenu();

    void saveAppSettings(appSettingsStruct tempSettings);

    void updateComboBoxValue(QComboBox *comboBox, const QString &message);
    void updateLineEditValue(QLineEdit *lineEdit, const QString &message);
    void updateSpinBoxValue(QSpinBox *spinBox, const QString &message);

    void setupGraphsOnce(int canvas_index, bool from_ui = false);
    void plotGraph(int canvas_index, int graphIndex, float_t value);

    void on_cmb_graph_selector_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QSerialPortInfo info;

    QString serialBuffer;

    double valueA;
    double valueV;
    double valueT;

    int counterA;
    int counterV;

    uint8_t flagMeasureDone;
    uint8_t buttonState;

    QTimer serialTimer;

    QTime time_;
    QCPRange DragStartHorzRange_;
    QCPRange DragStartVertRange_;
    QPoint mDragStart_;
    bool isMouseHold_;
    QElapsedTimer mouseHoldTimer_;

    appSettings settingsUI_;

    /* Необходимые настройки для COM-порта */
    int bufferSize_;
    QString messageCode_;

    QSerialPort::BaudRate baudRate_;
    QSerialPort::DataBits dataBits_;
    QSerialPort::Parity parityControl_;
    QSerialPort::StopBits stopBits_;
    QSerialPort::FlowControl flowControl_;

    QTextEdit thermoHelp;

    QCustomPlot *activeCanvas;  // Указатель на активный канвас
};

#endif // MAINWINDOW_H
