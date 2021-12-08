#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::set(employe a)
{
    e=a;
}

void menu::on_pushButton_clicked()
{
   // if(e.get_role()=="Responsable resourse humaine")
        zz.show();
}

void menu::on_pushButton_2_clicked()
{
    //if((e.get_role()=="Responsable resourse humaine")||(e.get_role()=="Responsable de plannification"))
        v.show();
}

void menu::on_pushButton_3_clicked()
{
    cl.show();
}

void menu::on_pushButton_5_clicked()
{
    m.show();
}
