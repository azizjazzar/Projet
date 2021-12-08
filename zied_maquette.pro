QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT += sql
QT += core gui charts
QT += printsupport
QT +=core gui serialport
QT +=widgets network
greaterThan(QT_MAJOR_VERSION, 4):QT +=widgets

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    carte.cpp \
    client.cpp \
    client_j.cpp \
    facture.cpp \
    gestionvoyage.cpp \
    menu.cpp \
    mikhail_facture.cpp \
    smtp.cpp \
    zied_account.cpp \
    zied_arduino.cpp \
    zied_connection.cpp \
    zied_dialog.cpp \
    zied_employe.cpp \
    main.cpp \
    zied_mainwindow.cpp\
    voyage.cpp\
    piechartwidget.cpp

HEADERS += \
    arduino.h \
    carte.h \
    client.h \
    client_j.h \
    facture.h \
    gestionvoyage.h \
    menu.h \
    mikhail_facture.h \
    smtp.h \
    zied_account.h \
    zied_arduino.h \
    zied_connection.h \
    zied_dialog.h \
    zied_employe.h \
    zied_mainwindow.h\
    voyage.h\
    piechartwidget.h

FORMS += \
    client_j.ui \
    gestionvoyage.ui \
    menu.ui \
    mikhail_facture.ui \
    zied_account.ui \
    zied_dialog.ui \
    zied_mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
