#ifndef CLIENT_JJ
#define CLIENT_JJ

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class client_j; }
QT_END_NAMESPACE

class client_j : public QMainWindow
{
    Q_OBJECT

public:
    client_j(QWidget *parent = nullptr);
    ~client_j();

private slots:

     void on_ajouter_clicked();

    void on_calendrier_clicked();

    void on_accueil_clicked();

    void on_statistique_clicked();


    void on_gestionclient_clicked();

    void on_reset_clicked();

    void on_Fonctionalite_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_recherche_2_clicked();

    void on_recherche_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_statistique_2_clicked();

private:
    Ui::client_j *ui;
};
#endif // CLIENT_JJ
