#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facture.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool verif_reference();
    bool verif_nom();
    bool verif_prenom();
    bool verif_date();
private slots:


    void on_ajouter_facture_clicked();

    void on_modifier_facture_clicked();

    void on_supprimer_facture_clicked();

    void on_afficher_clicked();

    void on_tab_facture_activated(const QModelIndex &index);



private:
    Ui::MainWindow *ui;
    QTimer * timerr ;
    Facture tmp_facture ;
    QPixmap PixTrueIcon;
    QPixmap PixFalseIcon;
    QPixmap background ;



};

#endif // MAINWINDOW_H
