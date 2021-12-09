#include "Selim_connection.h"
#include "Selim_mainwindow.h"
connection::connection(){}

bool connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
    db.setDatabaseName("Source_projet2A");
    db.setUserName("Selim");
    db.setPassword("2012611");

    if (db.open()) test=true;

    return test;

}

void connection::closeconnection()
{
    db.close();
}
