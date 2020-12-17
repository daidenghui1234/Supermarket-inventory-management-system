#-------------------------------------------------
#
# Project created by QtCreator 2020-11-16T19:14:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mywidget.cpp \
    login.cpp \
    register.cpp \
    user.cpp \
    supplierform.cpp \
    usermanangeform.cpp \
    goodmanangeform.cpp \
    inform.cpp \
    outform.cpp \
    statementform.cpp \
    mysql.cpp \
    supplier.cpp \
    goods.cpp \
    commodityaddform.cpp \
    readonlydelegate.cpp \
    warningform.cpp

HEADERS += \
        mywidget.h \
    login.h \
    register.h \
    mysql.h \
    user.h \
    supplierform.h \
    usermanangeform.h \
    goodmanangeform.h \
    inform.h \
    outform.h \
    statementform.h \
    supplier.h \
    goods.h \
    commodityaddform.h \
    readonlydelegate.h \
    warningform.h

FORMS += \
        mywidget.ui \
    login.ui \
    register.ui \
    supplierform.ui \
    usermanangeform.ui \
    goodmanangeform.ui \
    inform.ui \
    outform.ui \
    statementform.ui \
    commodityaddform.ui \
    warningform.ui
