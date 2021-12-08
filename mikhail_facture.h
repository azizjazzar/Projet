#ifndef mikhail_facture_H
#define mikhail_facture_H

#include <QMainWindow>
#include "facture.h"
#include<QTimer>
#include "zied_arduino.h"


namespace Ui {
class mikhail_facture;
}

class mikhail_facture : public QMainWindow
{
    Q_OBJECT

public:
    explicit mikhail_facture(QWidget *parent = nullptr);
    ~mikhail_facture();

    bool verif_reference();
    bool verif_nom();
    bool verif_prenom();
    bool verif_date();
    void mailSent(QString status);
private slots:


    void on_ajouter_facture_clicked();

    void on_modifier_facture_clicked();

    void on_supprimer_facture_clicked();

    void on_afficher_clicked();

    void on_tab_facture_activated(const QModelIndex &index);



    void on_email_clicked();

    void on_sendBtn_2_clicked();

    void on_browseBtn_2_clicked();

    void on_pdf_clicked();

    void on_pushButton_clicked();


    void on_stat_clicked();

    void on_return_3_clicked();


    void on_notepad_clicked();

    void on_trier_facture_clicked();


    void on_recherche_facture_textChanged(const QString &arg1);

    void on_rcpt_2_cursorPositionChanged(int arg1, int arg2);
    void update_label();

private:
    Ui::mikhail_facture *ui;
    QTimer * timerr ;
    Facture tmp_facture ;
    QPixmap PixTrueIcon;
    QPixmap PixFalseIcon;
    QPixmap background ;
    QPixmap bus ;

    QStringList files;
    arduino a;
    QByteArray data;




};

#endif // mikhail_facture_H
