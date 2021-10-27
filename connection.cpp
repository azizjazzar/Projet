#include "connection.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("kisheu-db");
db.setUserName("ali");//inserer nom de l'utilisateur
db.setPassword("jazzar");//inserer mot de passe de cet utilisateur
return db.open();
}


