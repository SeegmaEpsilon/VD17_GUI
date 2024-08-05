#ifndef UARTRECEIVER_H
#define UARTRECEIVER_H

#include <QObject>
#include <QSerialPort>
#include <QMessageBox>
#include <QDebug>

class UARTReceiver : public QObject
{
    Q_OBJECT
  public:
    explicit UARTReceiver(QObject *parent = 0);
    ~UARTReceiver();

  signals:
    void dataReceived(const QByteArray &data);

  public slots:
    void initializeUART(const QString &name);
    void deinitializeUART(const QString &name);

  private:
    QSerialPort *serialPort;
};

#endif // UARTRECEIVER_H
