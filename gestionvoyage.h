#ifndef GESTIONVOYAGE_H
#define GESTIONVOYAGE_H

#include <QMainWindow>
#include "voyage.h"
#include <QString>

namespace Ui {
class gestionvoyage;
}

class gestionvoyage : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionvoyage(QWidget *parent = nullptr);
    ~gestionvoyage();
    QString getVal();
private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_supprimer_clicked();
    void on_tab_voyage_activated(const QModelIndex &index);
    void on_pushButton_modifier_clicked();
    void on_pushButton_modifierr_clicked();
    void on_pushButton_clicked();
    void on_pushButton_annuler_clicked();
    void on_pushButton_rechercher_clicked();
    void on_pushButton_trier_clicked();
    void on_pushButton_ok_2_clicked();
    void on_pushButton_annuler_2_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::gestionvoyage *ui;
    Voyage V;
    QString val;
    int r=0;
};

#endif // GESTIONVOYAGE_H
