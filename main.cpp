
#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    if (c.createconnect())
        {
        MainWindow w;
        w.show();
        w.setFixedSize(1200,850);
        QMessageBox msgBox;

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
