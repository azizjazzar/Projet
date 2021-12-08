#include "carte.h"
#include "QMessageBox"
carte::carte()
{

}
void carte::setid(QString x)
{
id=x;
}
carte::carte(QString id,QString point)
{
this->id=id;
this->point=point;
}

QSqlQueryModel * carte::afficher()
{

    QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    query.prepare(QString("Select * from carte"));
    query.exec();
    model->setQuery(query);
    return model;
}
bool carte::ajouter()
{
QSqlQuery query;
query.prepare("insert into carte (id_client,point) values (:id,:point);");
query.bindValue(":id",id);
query.bindValue(":point",point);
return query.exec();
}
bool carte::update()
{

    QSqlQuery query;
    query.prepare(QString("update carte set point=:point where id_client=:id"));
    query.bindValue(":id",id);
    query.bindValue(":point",point);
    return query.exec();

}
bool carte::supprimer()
{
    QSqlQuery query;
    query.prepare(QString("DELETE from carte where id_client=:id"));
    query.bindValue(":id",id);
    return query.exec();
}
QString  carte::recherchee()
{
    QSqlQuery query;
    query.prepare(QString("select id from carte where id=:id"));
    query.bindValue(0,id);
    query.exec();
    query.next();
    return query.value(0).toString();


}
