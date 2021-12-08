#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include "zied_employe.h"
#include "zied_arduino.h"
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


private:
    Ui::account *ui;
    employe e;
    arduino a;
    QByteArray data;
    bool valid=false;
};

#endif // ACCOUNT_H
