#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include "employe.h"
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


private:
    Ui::account *ui;
    employe e;
};

#endif // ACCOUNT_H
