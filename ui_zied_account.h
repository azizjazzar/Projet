/********************************************************************************
** Form generated from reading UI file 'zied_account.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZIED_ACCOUNT_H
#define UI_ZIED_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_account
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *ajout_nom;
    QLabel *label_2;
    QLineEdit *ajout_prenom;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *ajout_login;
    QLabel *label_6;
    QLineEdit *ajout_password;
    QDateEdit *ajout_date;
    QLabel *label_7;
    QLineEdit *ajout_cin;
    QLabel *label_8;
    QLineEdit *ajout_num;
    QLabel *label_9;
    QLineEdit *ajout_email;
    QLineEdit *ajout_role;
    QTableView *tableView;

    void setupUi(QDialog *account)
    {
        if (account->objectName().isEmpty())
            account->setObjectName(QStringLiteral("account"));
        account->resize(611, 543);
        groupBox = new QGroupBox(account);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 591, 531));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 201, 491));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 47, 14));
        ajout_nom = new QLineEdit(groupBox_2);
        ajout_nom->setObjectName(QStringLiteral("ajout_nom"));
        ajout_nom->setGeometry(QRect(10, 40, 171, 20));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 47, 14));
        ajout_prenom = new QLineEdit(groupBox_2);
        ajout_prenom->setObjectName(QStringLiteral("ajout_prenom"));
        ajout_prenom->setGeometry(QRect(10, 90, 171, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 101, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 330, 47, 14));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 380, 47, 14));
        ajout_login = new QLineEdit(groupBox_2);
        ajout_login->setObjectName(QStringLiteral("ajout_login"));
        ajout_login->setGeometry(QRect(10, 400, 171, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 430, 61, 16));
        ajout_password = new QLineEdit(groupBox_2);
        ajout_password->setObjectName(QStringLiteral("ajout_password"));
        ajout_password->setGeometry(QRect(10, 450, 171, 20));
        ajout_date = new QDateEdit(groupBox_2);
        ajout_date->setObjectName(QStringLiteral("ajout_date"));
        ajout_date->setGeometry(QRect(10, 140, 171, 22));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 170, 47, 14));
        ajout_cin = new QLineEdit(groupBox_2);
        ajout_cin->setObjectName(QStringLiteral("ajout_cin"));
        ajout_cin->setGeometry(QRect(10, 190, 171, 20));
        ajout_cin->setMaxLength(8);
        ajout_cin->setClearButtonEnabled(false);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 220, 101, 16));
        ajout_num = new QLineEdit(groupBox_2);
        ajout_num->setObjectName(QStringLiteral("ajout_num"));
        ajout_num->setGeometry(QRect(10, 240, 171, 20));
        ajout_num->setMaxLength(8);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 280, 71, 16));
        ajout_email = new QLineEdit(groupBox_2);
        ajout_email->setObjectName(QStringLiteral("ajout_email"));
        ajout_email->setGeometry(QRect(10, 300, 171, 20));
        ajout_role = new QLineEdit(groupBox_2);
        ajout_role->setObjectName(QStringLiteral("ajout_role"));
        ajout_role->setGeometry(QRect(10, 350, 171, 20));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(230, 30, 341, 481));

        retranslateUi(account);

        QMetaObject::connectSlotsByName(account);
    } // setupUi

    void retranslateUi(QDialog *account)
    {
        account->setWindowTitle(QApplication::translate("account", "account", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("account", "Account", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("account", "info", Q_NULLPTR));
        label->setText(QApplication::translate("account", "Nom:", Q_NULLPTR));
        label_2->setText(QApplication::translate("account", "Prenom:", Q_NULLPTR));
        label_3->setText(QApplication::translate("account", "date de naissanse:", Q_NULLPTR));
        label_4->setText(QApplication::translate("account", "Role:", Q_NULLPTR));
        label_5->setText(QApplication::translate("account", "Login:", Q_NULLPTR));
        label_6->setText(QApplication::translate("account", "password:", Q_NULLPTR));
        label_7->setText(QApplication::translate("account", "CIN:", Q_NULLPTR));
        label_8->setText(QApplication::translate("account", "Numero telephone:", Q_NULLPTR));
        label_9->setText(QApplication::translate("account", "Adresse email:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class account: public Ui_account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZIED_ACCOUNT_H
