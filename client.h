#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include "connection.h"
/*
typedef struct dates
{
int day;
int mounth;
int year;
}dates;
*/

class Client
{
public:
    //constructeurs
    Client();
    Client(QString id,QString nom,QString prenom,QString adresse,QString genre,QString date_nais);
    //get
    QString getid();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getgenre();
    QString getdate_nais();
    //set
    void setid(QString id);
    void setnom(QString nom);
    void setprenom(QString prenom);
    void setadresse(QString adresse);
    void setgenre(QString genre);
    void setdate_nais(QString date_nais);
    //Crud
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer();
    bool update();

private:
    QString id;
    QString nom ;
    QString prenom;
    QString adresse;
    QString date_nais;
    QString genre;


};

#endif // CLIENT_H
