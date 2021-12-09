#include "Selim_notification.h"
#include "Selim_mainwindow.h"
#include <QDebug>
ActiveAb::ActiveAb()
{

}

ActiveAb::ActiveAb(QString A,QString B,QString C,QString D)
{
    A = cin;
    B = type;
    C = DateStart;
    D = DateFin;
}

void ActiveAb::SetDateStart(QString cin)
{
    QSqlQuery query;
    QString DateAct = QDateTime::currentDateTime().toString();
    query.exec("insert into ACTIVE_AB (DATESTART)"
               "VALUES('"+DateAct+"')  where CIN = '"+cin+"'");
}

QDate ActiveAb::GetDateFin(QString Du)
{
    QString M1 = Du.at(0);
    //QString M2 = Du.at(2);
    int M =  M1.toInt();
    QString D1 = Du.at(2);
    QString D2 = Du.at(3);
    int D = (D1+D2).toInt();
    QDate DateFin = QDate::currentDate().addMonths(M).addDays(D);
    return DateFin;
}

void ActiveAb::create_notifs(QString cin,QString type)
{
    QSqlQuery qry;
    qry.exec("insert into ACTIVE_AB (CIN,ID)"
    "VALUES ('"+cin+"','"+type+"')");
    QString du;
    QDate ds, cd = QDate::currentDate();
    SetDateStart(cin);
    qry.exec("select DUREE from ABONNEMENT where ID = '"+type+"'");
    while(qry.next()) du = qry.value(0).toString();
    ds = GetDateFin(du);
    qry.prepare("insert into ACTIVE_AB (DATESTART,DATEEND)"
             "VALUES (:DATESTART,:DATEEND) where CIN ='"+cin+"'");
    qry.bindValue(":DATESTART",cd);
    qry.bindValue(":DATEEND",ds);
    qry.exec();
}

bool ActiveAb::renouv(Ui::Selim_MainWindow *ui)
{
    QString ref=ui->tab_renouv->model()->data(ui->tab_renouv->model()->index(ui->tab_renouv->selectionModel()->currentIndex().row(),1)).toString();
    QSqlQuery qry;
    QString du;
    QDate DateAct = QDate::currentDate() , ds;
    qry.prepare("select DUREE from ABONNEMENT where ID = '"+ref+"'");
    qry.exec();
    while(qry.next())
        du = qry.value(0).toString();
    qDebug() << du;
    ds = GetDateFin(du);
    qDebug() << ds;
    qry.prepare("select * FROM ACTIVE_AB WHERE ID ='"+ref+"'");
    qry.exec();
    int total=0;
    while(qry.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("update ACTIVE_AB set DATESTART = :DATESTART,DATEEND = :DATEEND where ID= '"+ref+"'");
        q.bindValue(":DATESTART",DateAct);
        q.bindValue(":DATEEND",ds);
    return  q.exec();}
            else return false;
}

QSqlQueryModel * ActiveAb::afficher_notifs()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * "
                    "from ACTIVE_AB where TO_DATE(DATEEND,'DD-MM-YY')<sysdate");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATESTART"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEEND"));

    return model;
}
