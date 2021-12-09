#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include "Selim_mainwindow.h"

class connection
{ QSqlDatabase db;
public:
    connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNECTION_H
