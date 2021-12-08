#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include "zied_employe.h"
#include "zied_arduino.h"
#include "facture.h"
namespace Ui {
class account;
}

class account : public QDialog
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = nullptr);
    ~account();
    void set(employe a);

private slots:
    void update_label();
     void update_label1();


private:
    Ui::account *ui;
    employe e;
    arduino a;
    QByteArray data;
    bool valid=false;
    Facture tmp_facture;
};

#endif // ACCOUNT_H
