#include "notification.h"

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

/*void ActiveAb::SetDateStart(QString cin, QString type)
{
    QSqlQuery query;
    QString DateAct = QDateTime::currentDateTime().toString();
    query.prepare("insert where")
}
*/
