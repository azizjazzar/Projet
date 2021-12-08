#include "zied_connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2a");
db.setUserName("ali");//inserer nom de l'utilisateur
db.setPassword("jazzar");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}

void Connection::closeconnection()
{
    db.close();
}
