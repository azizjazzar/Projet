/********************************************************************************
** Form generated from reading UI file 'zied_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZIED_MAINWINDOW_H
#define UI_ZIED_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *ajout_nom;
    QLabel *label_2;
    QLineEdit *ajout_prenom;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *ajout_role;
    QLabel *label_5;
    QLineEdit *ajout_login;
    QLabel *label_6;
    QLineEdit *ajout_password;
    QDateEdit *ajout_date;
    QPushButton *pushButton_ajout;
    QLabel *label_7;
    QLineEdit *ajout_cin;
    QLabel *label_8;
    QLineEdit *ajout_num;
    QLabel *label_9;
    QLineEdit *ajout_email;
    QGroupBox *groupBox_8;
    QGroupBox *groupBox_9;
    QLabel *label_17;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_aff;
    QLineEdit *lineEdit_15;
    QComboBox *comboBox_5;
    QLabel *label_21;
    QComboBox *comboBox_7;
    QPushButton *pushButton_11;
    QLabel *label_22;
    QComboBox *comboBox_8;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QLabel *label_10;
    QLineEdit *cin_mod;
    QLabel *label_12;
    QComboBox *attribut_mod;
    QLabel *label_13;
    QLineEdit *mod_val;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_supp;
    QGroupBox *groupBox_4;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QPushButton *pushButton_2;
    QFrame *frame;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(987, 585);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 991, 571));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 201, 521));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 47, 14));
        ajout_nom = new QLineEdit(groupBox);
        ajout_nom->setObjectName(QStringLiteral("ajout_nom"));
        ajout_nom->setGeometry(QRect(10, 40, 171, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 47, 14));
        ajout_prenom = new QLineEdit(groupBox);
        ajout_prenom->setObjectName(QStringLiteral("ajout_prenom"));
        ajout_prenom->setGeometry(QRect(10, 90, 171, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 101, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 330, 47, 14));
        ajout_role = new QComboBox(groupBox);
        ajout_role->setObjectName(QStringLiteral("ajout_role"));
        ajout_role->setGeometry(QRect(10, 350, 171, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 380, 47, 14));
        ajout_login = new QLineEdit(groupBox);
        ajout_login->setObjectName(QStringLiteral("ajout_login"));
        ajout_login->setGeometry(QRect(10, 400, 171, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 430, 61, 16));
        ajout_password = new QLineEdit(groupBox);
        ajout_password->setObjectName(QStringLiteral("ajout_password"));
        ajout_password->setGeometry(QRect(10, 450, 171, 20));
        ajout_date = new QDateEdit(groupBox);
        ajout_date->setObjectName(QStringLiteral("ajout_date"));
        ajout_date->setGeometry(QRect(10, 140, 171, 22));
        pushButton_ajout = new QPushButton(groupBox);
        pushButton_ajout->setObjectName(QStringLiteral("pushButton_ajout"));
        pushButton_ajout->setGeometry(QRect(60, 480, 75, 23));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 170, 47, 14));
        ajout_cin = new QLineEdit(groupBox);
        ajout_cin->setObjectName(QStringLiteral("ajout_cin"));
        ajout_cin->setGeometry(QRect(10, 190, 171, 20));
        ajout_cin->setMaxLength(8);
        ajout_cin->setClearButtonEnabled(false);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 220, 101, 16));
        ajout_num = new QLineEdit(groupBox);
        ajout_num->setObjectName(QStringLiteral("ajout_num"));
        ajout_num->setGeometry(QRect(10, 240, 171, 20));
        ajout_num->setMaxLength(8);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 280, 71, 16));
        ajout_email = new QLineEdit(groupBox);
        ajout_email->setObjectName(QStringLiteral("ajout_email"));
        ajout_email->setGeometry(QRect(10, 300, 171, 20));
        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(220, 0, 551, 521));
        groupBox_9 = new QGroupBox(groupBox_8);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(270, 20, 251, 131));
        label_17 = new QLabel(groupBox_9);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 10, 81, 16));
        lineEdit_14 = new QLineEdit(groupBox_9);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(10, 50, 221, 20));
        pushButton_8 = new QPushButton(groupBox_9);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 80, 221, 23));
        groupBox_10 = new QGroupBox(groupBox_8);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 20, 251, 131));
        pushButton_9 = new QPushButton(groupBox_10);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 80, 91, 23));
        pushButton_aff = new QPushButton(groupBox_10);
        pushButton_aff->setObjectName(QStringLiteral("pushButton_aff"));
        pushButton_aff->setGeometry(QRect(140, 80, 91, 23));
        lineEdit_15 = new QLineEdit(groupBox_10);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(10, 50, 221, 20));
        comboBox_5 = new QComboBox(groupBox_10);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(10, 10, 221, 22));
        label_21 = new QLabel(groupBox_8);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 430, 81, 16));
        comboBox_7 = new QComboBox(groupBox_8);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));
        comboBox_7->setGeometry(QRect(20, 450, 191, 22));
        pushButton_11 = new QPushButton(groupBox_8);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(404, 450, 121, 23));
        label_22 = new QLabel(groupBox_8);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(230, 430, 47, 14));
        comboBox_8 = new QComboBox(groupBox_8);
        comboBox_8->setObjectName(QStringLiteral("comboBox_8"));
        comboBox_8->setGeometry(QRect(230, 450, 151, 22));
        tableView = new QTableView(groupBox_8);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 160, 511, 261));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(780, 0, 191, 211));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 151, 16));
        cin_mod = new QLineEdit(groupBox_2);
        cin_mod->setObjectName(QStringLiteral("cin_mod"));
        cin_mod->setGeometry(QRect(10, 40, 171, 20));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 70, 141, 16));
        attribut_mod = new QComboBox(groupBox_2);
        attribut_mod->setObjectName(QStringLiteral("attribut_mod"));
        attribut_mod->setGeometry(QRect(10, 90, 171, 22));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 120, 101, 16));
        mod_val = new QLineEdit(groupBox_2);
        mod_val->setObjectName(QStringLiteral("mod_val"));
        mod_val->setGeometry(QRect(10, 140, 171, 20));
        pushButton_mod = new QPushButton(groupBox_2);
        pushButton_mod->setObjectName(QStringLiteral("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(110, 170, 75, 23));
        pushButton_supp = new QPushButton(groupBox_2);
        pushButton_supp->setObjectName(QStringLiteral("pushButton_supp"));
        pushButton_supp->setGeometry(QRect(10, 170, 75, 23));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(780, 210, 191, 311));
        textBrowser = new QTextBrowser(groupBox_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 171, 261));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 460, 75, 23));
        frame = new QFrame(tab_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 40, 811, 411));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(250, 460, 321, 20));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(590, 460, 121, 23));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 987, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "gestion des employ\303\251s", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "ajouter employ\303\251", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Prenom:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "date de naissanse:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Role:", Q_NULLPTR));
        ajout_role->clear();
        ajout_role->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Responsable resourse humaine", Q_NULLPTR)
         << QApplication::translate("MainWindow", "chauffeur", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("MainWindow", "Login:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "password:", Q_NULLPTR));
        pushButton_ajout->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "CIN:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Numero telephone:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Adresse email:", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "affichier/rechercher employ\303\251", Q_NULLPTR));
        groupBox_9->setTitle(QString());
        label_17->setText(QApplication::translate("MainWindow", "CIN d'employ\303\251:", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Affichier l'emploi du temp pour se semain", Q_NULLPTR));
        groupBox_10->setTitle(QString());
        pushButton_9->setText(QApplication::translate("MainWindow", "rechercher", Q_NULLPTR));
        pushButton_aff->setText(QApplication::translate("MainWindow", "affichier tout", Q_NULLPTR));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "rechercher par CIN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "rechercher par nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "rechercher par prenom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "rechercher par role", Q_NULLPTR)
        );
        label_21->setText(QApplication::translate("MainWindow", "tri\303\251 le tableau:", Q_NULLPTR));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "par ordre alphebetique de prenom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "par ordre alphebetique de nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "par ordre alphebetique de login", Q_NULLPTR)
         << QApplication::translate("MainWindow", "par ordre alphebetique de email", Q_NULLPTR)
        );
        pushButton_11->setText(QApplication::translate("MainWindow", "Trier le tableau", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "ordre:", Q_NULLPTR));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "croissant", Q_NULLPTR)
         << QApplication::translate("MainWindow", "d\303\251croissant", Q_NULLPTR)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "modifier un employ\303\251", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "CIN d'employ\303\251 a modifier:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "attribut a modifier:", Q_NULLPTR));
        attribut_mod->clear();
        attribut_mod->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Prenom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "CIN", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Role", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Email", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Telephone", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("MainWindow", "sa nouveau valeur:", Q_NULLPTR));
        pushButton_mod->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        pushButton_supp->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "msg d'erreur:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "gerer la liste des employ\303\251s", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Exporter", Q_NULLPTR));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "                                  Full file destination", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Use preset destination", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "statistic", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZIED_MAINWINDOW_H
