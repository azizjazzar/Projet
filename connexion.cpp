#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("imenmn");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return  test;
}
void connexion::closeConexion()
{
    db.close();
}
