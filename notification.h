#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <ui_mainwindow.h>

class ActiveAb
{
private:
    QString cin;
    QString type;
    QString DateStart;
    QString DateFin;


public:
    ActiveAb();
    ActiveAb(QString,QString,QString,QString);
    void SetDateStart(QString,QString);
};

#endif // NOTIFICATION_H
