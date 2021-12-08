#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
    void closeconnection();
private:
    QSqlDatabase db;
};

#endif // CONNECTION_H
