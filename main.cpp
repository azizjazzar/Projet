#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <ui_mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
       w.show();
       QMessageBox::information(nullptr,QObject::tr("DataBase open successfully"),
       QObject::tr("connection successful.\n"
                   "click cancel to exit."),QMessageBox::Cancel);
    }
    else QMessageBox::critical(nullptr,QObject::tr("DataBase failed to open"),
                                  QObject::tr("connection failed.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
    w.setFixedSize(820,490);
    return a.exec();
}
