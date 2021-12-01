#include "voyage.h"
#include  <QSqlQuery>
#include <QTDebug>
#include<QString>
#include <QObject>
#include <QDate>
#include <QVariant>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include "ui_mainwindow.h"
#include<QSqlRecord>
#include <QPrintDialog>
#include<QTextStream>
#include<QFile>


Voyage::Voyage()
{
     ref="";
     cin_chauffeur="";
     etat="";
     date="";
     heure_arrive="";
     heure_depart="";
     heure_arrive_prevu="";
     destination="";
     depart_bus="";

}
Voyage::Voyage (QString ref,QString cin_chauffeur,QString matricule,QString etat,QString depart_bus,QString destination,QString date ,QString heure_depart,QString heure_arrive_prevu,QString heure_arrive)
{
 this ->ref=ref;
 this ->cin_chauffeur=cin_chauffeur;
 this ->matricule=matricule;
 this ->etat=etat;
 this ->date =date;
 this ->heure_arrive=heure_arrive;
 this ->heure_arrive_prevu=heure_arrive_prevu;
 this ->heure_depart=heure_depart;
 this->depart_bus=depart_bus;
 this ->destination=destination ;
}
QString Voyage::get_ref()
{
    return  ref;
}
void Voyage::set_ref(QString r)
{
      ref=r;
}
bool Voyage::ajouter_voyage()
{

        QSqlQuery query;

        QDate Date=QDate::fromString(date,"MM/dd/yyyy");
        QTime depart=QTime::fromString(heure_depart,"h:mm AP");
        QTime arrivep=QTime::fromString(heure_arrive_prevu,"h:mm AP");
       QTime arrive=QTime::fromString(heure_arrive,"h:mm AP");
        query.prepare("INSERT INTO voyage (reference, cin_chauffeur, matricule,etat,date_d,heure_depart,heure_arrivep,heure_arrive,depart,destination) "
                      "VALUES (:reference, :cin_chauffeur, :matricule, :etat, :date_d, :heure_depart, :heure_arrivep, :heure_arrive, :depart, :destination)");
        query.bindValue(":reference", ref);
        query.bindValue(":cin_chauffeur", cin_chauffeur);
        query.bindValue(":matricule", matricule);
        query.bindValue(":etat", etat);
        query.bindValue(":depart", depart_bus);
        query.bindValue(":destination", destination);
        query.bindValue(":date_d", Date);
        query.bindValue(":heure_depart",depart);
        query.bindValue(":heure_arrivep", arrivep);
        query.bindValue(":heure_arrive",arrive);
        return query.exec();

}
QSqlQueryModel * Voyage::afficher_voyage()
{
    QSqlQueryModel * model=new QSqlQueryModel();
      model->setQuery("SELECT* FROM voyage");
      return model;
}

bool Voyage::supprimer_voyage(QString reff)
{
  if (reff!="")
    {QSqlQuery query ;
    query.prepare("Delete from voyage where reference= :reference");
    query.bindValue(0,reff);
    return  query.exec();}

}

bool Voyage::modifier_voyage( )
{

    QSqlQuery query;

 QDate Date=QDate::fromString(date,"MM/dd/yyyy");
 QTime depart=QTime::fromString(heure_depart,"h:mm AP");
 QTime arrivep=QTime::fromString(heure_arrive_prevu,"h:mm AP");
 QTime arrive=QTime::fromString(heure_arrive,"h:mm AP");
 query.prepare("UPDATE voyage set cin_chauffeur=:cin_chauffeur, matricule=:matricule,etat=:etat,date_d=:date_d,heure_depart=:heure_depart,heure_arrivep=:heure_arrivep,heure_arrive=:heure_arrive,depart=:depart,destination= :destination where reference= :reference");

    query.bindValue(":reference", ref);
    query.bindValue(":cin_chauffeur", cin_chauffeur);
    query.bindValue(":matricule", matricule);
    query.bindValue(":etat", etat);
    query.bindValue(":depart", depart_bus);
    query.bindValue(":destination", destination);
    query.bindValue(":date_d", Date);
    query.bindValue(":heure_depart",depart);
    query.bindValue(":heure_arrivep", arrivep);
    query.bindValue(":heure_arrive",arrive);
    return query.exec();
}

QSqlQueryModel *Voyage::rechercher(string choix,QString v,QString etat_voyage)
{
    QSqlQueryModel * model=new QSqlQueryModel();

if (etat_voyage.toStdString()=="Tous")

{ qDebug()<<"here";
    if (choix=="Reference ")
   {
    model->setQuery("SELECT* FROM voyage WHERE reference LIKE '"+v+"%'");

   }
   else if (choix=="Cin chauffeur")
   {
    model->setQuery("SELECT* FROM voyage WHERE cin_chauffeur LIKE '"+v+"%'");
   }
  /* else
   {
    model->setQuery("SELECT* FROM voyage WHERE date_d LIKE '"+v+"%'");
   }*/
}

else
{
    if (choix=="Reference ")
    {
    model->setQuery("SELECT* FROM voyage WHERE reference LIKE '"+v+"%' and  etat LIKE '"+etat_voyage+"'");
    }
    else if (choix=="Cin chauffeur")
    {
    model->setQuery("SELECT* FROM voyage WHERE cin_chauffeur LIKE '"+v+"%' and  etat LIKE '"+etat_voyage+"'");
    }
    /*else
    {
    model->setQuery("SELECT* FROM voyage WHERE date_d='"+v+"' and  etat LIKE '"+etat_voyage+"'");
    }*/
}

return model;
}
QSqlQueryModel* Voyage::trier(string par,string ordre)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if (par=="Reference ")
    {
      if (ordre=="croissant ")
      {
          model->setQuery("SELECT* FROM voyage ORDER BY reference ASC");
      }
      else
      {
          model->setQuery("SELECT* FROM voyage ORDER BY reference DESC");
      }
    }
    if (par=="Date")
    {
        if (ordre=="croissant ")
        {
            model->setQuery("SELECT* FROM voyage ORDER BY date_d ASC");
        }
        else
        {
             model->setQuery("SELECT* FROM voyage ORDER BY date_d DESC");
        }
    }
    return model;
}

void Voyage::PrintTable( QPrinter* printer, QSqlQuery&  Query )
{
    QString strStream;
      QTextStream out(&strStream);

      const int rowCount = Query.size();
      const int columnCount = Query.record().count();

      out <<  "<html>\n"
          "<head>\n"
          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
          <<  QString("<title>%1</title>\n").arg("TITLE OF TABLE")
          <<  "</head>\n"
          "<body bgcolor=#ffffff link=#5000A0>\n"
          "<table border=1 cellspacing=0 cellpadding=2>\n";

      // headers
      out << "<thead><tr bgcolor=#f0f0f0>";
      for (int column = 0; column < columnCount; column++)
        out << QString("<th>%1</th>").arg(Query.record().fieldName(column));
      out << "</tr></thead>\n";

      while (Query.next()) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
          QString data = Query.value(column).toString();
          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        out << "</tr>\n";
      }

      out <<  "</table>\n"
          "</body>\n"
          "</html>\n";

      QTextDocument document;
      document.setHtml(strStream);
      document.print(printer);
}
void Voyage::exporter_PDF(string choice)
{

     QPrinter printer(QPrinter::HighResolution);
     printer.setOrientation(QPrinter::Portrait);
     printer.setPageSize(QPrinter::A4);
     printer.setOutputFormat(QPrinter::PdfFormat);
    if (choice=="Tous les voyages ")
     printer.setOutputFileName("tous_les_voyages.pdf");
    else
     printer.setOutputFileName("voyages_en_Retard.pdf");
    QPrintDialog dlg(&printer, 0);
   // if(dlg.exec() == QDialog::Accepted) {
     QSqlQuery query;
     if (choice=="Tous les voyages ")
     query.prepare("SELECT * from voyage");
     else
     query.prepare("SELECT * FROM voyage WHERE etat LIKE 'en retard '");
     query.exec();
     PrintTable(&printer, query);
  //  }

}
void Voyage::exporter_excel(string choice)
{
    if (choice=="Tous les voyages ")
    {QFile data("tous_les_voyages.csv");
    if (data.open(QFile::WriteOnly)) {
        QTextStream outTxt(&data);
        QSqlQuery query;
        bool firstLine=true;
        query.prepare("SELECT * FROM voyage");
        if(query.exec()){
            while (query.next()) {
                const QSqlRecord recrd= query.record();
                if(firstLine){
                   // for(int i=0;i<recrd.count();++i)
                   //     outTxt << recrd.field(i) << ','; //Headers
                }
                firstLine=false;
                outTxt << "\r\n";
                for(int i=0;i<recrd.count();++i)
                    outTxt << recrd.value(i).toString() << ',';
            }
        }
        data.close();
    }
    }
    else
    {
        QFile data("voyages_en_Retard.csv");
            if (data.open(QFile::WriteOnly)) {
                QTextStream outTxt(&data);
                QSqlQuery query;
                bool firstLine=true;
                query.prepare("SELECT * FROM voyage WHERE etat LIKE 'en retard '");
                if(query.exec()){
                    while (query.next()) {
                        const QSqlRecord recrd= query.record();
                        if(firstLine){
                           // for(int i=0;i<recrd.count();++i)
                           //     outTxt << recrd.field(i) << ','; //Headers
                        }
                        firstLine=false;
                        outTxt << "\r\n";
                        for(int i=0;i<recrd.count();++i)
                            outTxt << recrd.value(i).toString() << ',';
                    }
                }
                data.close();
    }
}
}
QSqlQueryModel *Voyage::list_clients(QString val)
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT client_voyage.ref_voyage , client_voyage.id_client,client.nom FROM client_voyage FULL JOIN client ON client.id=client_voyage.id_client WHERE client_voyage.ref_voyage LIKE '"+val+"'");
   return model;
}

int Voyage::nbrevoyage()
{   int sum=0;
    QSqlQuery query;
    query.prepare("SELECT * FROM voyage ");

    if (query.exec())
    {
        while (query.next())
        {
            sum++;
        }
    }
     qDebug()<<sum;
     return sum;

}
int Voyage::nbrevoyage_enretard()
{
    int sum=0;
        QSqlQuery query;
        query.prepare("SELECT * FROM voyage where etat LIKE 'en retard '");

        if (query.exec())
        {
            while (query.next())
            {
                sum++;
            }
        }
         qDebug()<<sum;
         return sum;

}
int Voyage::nbrevoyage_termine()
{
    int sum=0;
        QSqlQuery query;
        query.prepare("SELECT * FROM voyage where etat LIKE 'termines'");

        if (query.exec())
        {
            while (query.next())
            {
                sum++;
            }
        }
         qDebug()<<sum;
         return sum;
}
int Voyage::nbrevoyage_planifies()
{
    int sum=0;
        QSqlQuery query;
        query.prepare("SELECT * FROM voyage where etat LIKE 'planifies'");

        if (query.exec())
        {
            while (query.next())
            {
                sum++;
            }
        }
         qDebug()<<sum;
         return sum;
}


