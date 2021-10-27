#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

     void on_ajouter_clicked();

    void on_calendrier_clicked();

    void on_accueil_clicked();

    void on_statistique_clicked();


    void on_gestionclient_clicked();

    void on_reset_clicked();

    void on_Fonctionalite_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
