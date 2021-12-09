#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_Selim_mainwindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Selim_MainWindow; }
QT_END_NAMESPACE

class Selim_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Selim_MainWindow(QWidget *parent = nullptr);
    ~Selim_MainWindow();

private slots:

  void on_ajouter_clicked();

  void on_supprimer_clicked();

  void on_pushButton_modifier_clicked();

  void on_pushButton_recherche_clicked();

  void on_pushButton_trier_clicked();

  void on_pushButton_clicked();

  void on_pushButton_4_clicked();

  void on_tabWidget_tabBarClicked(int index);

  void on_pushButton_2_clicked();

private:
    Ui::Selim_MainWindow *ui;
};
#endif // MAINWINDOW_H
