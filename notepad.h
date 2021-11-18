#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <QMainWindow>
#include<QFile>
#include<QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class notePad;
}

class notePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit notePad(QWidget *parent = nullptr);
    ~notePad();


private slots:
    void on_actionnouveau_triggered();

    void on_actionOuvrir_triggered();

    void on_actionEnregistrer_triggered();

    void on_actionPrint_triggered();

    void on_actionQuitter_triggered();

    void on_actionCopier_triggered();

    void on_actionColler_triggered();

    void on_actionCouper_triggered();

    void on_actionretour_triggered();

    void on_actionAnnuler_triggered();

private:
    Ui::notePad *ui;
    QString currentFile="";

};

#endif // NOTEPAD_H
