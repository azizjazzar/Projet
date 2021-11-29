#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
class arduino
{
public:
    arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray d);
    QByteArray read_from_arduino();
    QSerialPort * getserial();
    QString get_arduino_port_name();
private:
    QSerialPort * serial=new QSerialPort();
    static const quint16 arduino_uno_vendor_id=6790;
    static const quint16 arduino_uno_producy_id=29987;
    QString arduino_port_name;
    bool arduino_is_available=false;
    QByteArray data;
};

#endif // ARDUINO_H
