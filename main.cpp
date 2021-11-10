
#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    if (c.createconnect())
        {
        w.show();
        QMessageBox msgBox;
        w.setFixedSize(1156,812);
        return a.exec();
        }
    else
        {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Proléme");
        msgBox.setText("Connection echoué");
        msgBox.exec();

        }
}
