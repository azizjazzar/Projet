#ifndef CARTE_H
#define CARTE_H
#include"connection.h"

class carte
{
public:
    carte();
    carte(QString,QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer();
    bool update();
    QString  recherchee();

    //sett
    void setid(QString);

private:
    QString point ;
    QString id;
};

#endif // CARTE_H
