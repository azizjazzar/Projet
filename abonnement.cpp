#include "abonnement.h"

abonnement::abonnement()
{

}

bool abonnement::set_duree(QString i,QString Duree)
{
    QSqlQuery query;
    query.prepare("select FROM ABONNEMENT WHERE ID= '"+i+"'");
    query.prepare("INSERT INTO ABONNEMENT (ID,DUREE,PRIX) "
                        "VALUES (:DUREE)");
    query.bindValue(":DUREE",Duree);
    return query.exec();
}

bool abonnement::set_prix(QString i,int Prix)
{
    QSqlQuery query;
    query.prepare("select FROM ABONNEMENT WHERE ID= '"+i+"'");
    query.prepare("INSERT INTO ABONNEMENT (ID,DUREE,PRIX) "
                        "VALUES (:PRIX)");
    query.bindValue(":PRIX",Prix);
    return query.exec();
}

abonnement::abonnement(QString ID,QString Duree,int Prix)
{
    this -> ID = ID;
    this -> Duree = Duree;
    this -> Prix = Prix;
}

bool abonnement::ajouter_abonnement(QString A,QString B,int C)
{
    QSqlQuery query;
    query.prepare("INSERT INTO ABONNEMENT (ID,DUREE,PRIX) "
                        "VALUES (:ID,:DUREE,:PRIX)");

    query.bindValue(":ID",A);
    query.bindValue(":DUREE",B);
    query.bindValue(":PRIX",C);

    return query.exec();
}

QSqlQueryModel * abonnement::afficher_abonnement()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * "
                    "from ABONNEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}

bool abonnement :: supprimer_abonnement(Ui::MainWindow *ui)
{
    QString ref=ui->tableView_ab->model()->data(ui->tableView_ab->model()->index(ui->tableView_ab->selectionModel()->currentIndex().row(),0)).toString();

        QSqlQuery query;
        query.prepare("select * FROM ABONNEMENT WHERE ID ='"+ref+"'");
        query.exec();
        int total=0;
        while(query.next()){
            total++;
        }
        if(total==1){
            QSqlQuery q;
            q.prepare("DELETE FROM ABONNEMENT WHERE ID ='"+ref+"'");
            return q.exec();
        }
        else
        {
            return false;
        }

}

/*bool abonnement::supprimer_abonnement(QString i)
{
    QSqlQuery query;
    query.prepare("Delete from ABONNEMENT where ID = :ID ");
    query.bindValue(":ID", i);
    return    query.exec();
}*/

bool abonnement::modifier_abonnement(QString A,QString B,int C)//Ui::MainWindow *ui))
{
    QSqlQuery query;
    query.prepare("UPDATE ABONNEMENT SET DUREE=:DUREE, PRIX=:PRIX WHERE ID= '"+A+"'");
    query.bindValue(":ID",A);
    query.bindValue(":DUREE",B);
    query.bindValue(":PRIX",C);

    return query.exec();
    /*QString ref=ui->tableView_ab->model()->data(ui->tableView_ab->model()->index(ui->tableView_ab->selectionModel()->currentIndex().row(),0)).toString();

        QSqlQuery query;
        query.prepare("select * FROM ABONNEMENT WHERE ID ='"+ref+"'");
        query.exec();
        int total=0;
        while(query.next()){
            total++;
        }
        if(total==1){
            QSqlQuery q;
            query.prepare("UPDATE ABONNEMENT SET DUREE=:DUREE, PRIX=:PRIX WHERE ID= '"+ref+"'");
            query.bindValue(":ID",A);
            query.bindValue(":DUREE",B);
            query.bindValue(":PRIX",C);
            return q.exec();
        }
        else
        {
            return false;
        }*/
}
