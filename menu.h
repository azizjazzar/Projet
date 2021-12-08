#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <gestionvoyage.h>
#include <zied_mainwindow.h>
#include "zied_employe.h"
#include <client_j.h>
namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
    void set(employe a);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::menu *ui;
    gestionvoyage v;
    MainWindow zz;
    client_j cl;
    employe e;

};

#endif // MENU_H
