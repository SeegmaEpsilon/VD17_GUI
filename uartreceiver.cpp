#include "uartreceiver.h"


UARTReceiver::UARTReceiver(QObject *parent) : QObject(parent)
{

}

UARTReceiver::~UARTReceiver()
{
  if (serialPort->isOpen())
    serialPort->close();
}

void UARTReceiver::initializeUART(const QString& name)
{
  serialPort = new QSerialPort();
  serialPort->setPortName(name);

  serialPort->setBaudRate(QSerialPort::Baud115200);
  serialPort->setDataBits(QSerialPort::Data8);
  serialPort->setParity(QSerialPort::NoParity);
  serialPort->setStopBits(QSerialPort::OneStop);
  serialPort->setFlowControl(QSerialPort::NoFlowControl);

  qDebug() << "Port open: " << serialPort->open(QIODevice::ReadOnly);
  qDebug() << "Port error: " << serialPort->errorString();

    while (true)
    {
        if (serialPort->waitForReadyRead(100))
        {
            QByteArray data = serialPort->readAll();
            emit dataReceived(data);
        }
    }
}

void UARTReceiver::deinitializeUART(const QString& name)
{
  serialPort->close();
}
