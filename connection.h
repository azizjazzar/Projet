#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>



class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
