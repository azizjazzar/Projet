#include "abonnement.h"
#include <ui_mainwindow.h>

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

}
QDate abonnement::GetDateFin(QString Du)
{
    QDate DateAct = QDate::currentDate();
    /*QString format = "yyyy/MM/dd ";
    QString DureeF = "0000/"+Du;
    QDate Duree = QDate::fromString(DureeF,format);*/
    QString M1 = Du.at(1);
    QString M2 = Du.at(2);
    int M =  (M1+M2).toInt();
    QString D1 = Du.at(4);
    QString D2 = Du.at(5);
    int D = (D1+D2).toInt();
    QDate DateFin = DateAct.addMonths(M).addDays(D);
    return DateFin;
}

QSqlQueryModel *abonnement::Rechercher(QString id)
  {   QSqlQuery query;
      QSqlQueryModel * model= new QSqlQueryModel();
      model->setQuery("select * from ABONNEMENT WHERE ID = '"+id+"'");
      /*id="%"+id+"%";
      query.bindValue(":id",id);
      query.exec();
      model->setQuery(query);*/
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
      return model;

  }


  QSqlQueryModel * abonnement::TrierDuree()
  {
      QSqlQuery *qry=new QSqlQuery();
      QSqlQueryModel *model=new QSqlQueryModel();
        qry->prepare("select * from ABONNEMENT order by DUREE ASC");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        qry->exec();
      model->setQuery(*qry);
      return model;
  }

  QSqlQueryModel * abonnement::TrierPrix()
  {
      QSqlQuery * qry=new QSqlQuery();
      QSqlQueryModel * model=new QSqlQueryModel();
        qry->prepare("select * from ABONNEMENT order by PRIX ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("DUREE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        qry->exec();
      model->setQuery(*qry);
      return model;
  }
