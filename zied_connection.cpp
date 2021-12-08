#include "zied_connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("mikhail");//inserer nom de l'utilisateur
db.setPassword("mikhail");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}

void Connection::closeconnection()
{
    db.close();
}
