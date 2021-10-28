#include "abonnement.h"

abonnement::abonnement()
{

}

abonnement::abonnement(QString ID,QString type,QString Duree,int Prix)
{
    this -> ID = ID;
    this -> type = type;
    this -> Duree = Duree;
    this -> Prix = Prix;
}
