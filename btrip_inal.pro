#-------------------------------------------------
#
# Project created by QtCreator 2018-08-03T13:27:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = btrip_inal
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
    abstractbooking.cpp \
    abstractuser.cpp \
    administratortab.cpp \
    amenities.cpp \
    btripdatabase.cpp \
    business.cpp \
    customer.cpp \
    customertab.cpp \
    detaildialog.cpp \
    hotel.cpp \
    hotelapplicationstep.cpp \
    hotelbooking.cpp \
    hotelmanaertab.cpp \
    hotelmanager.cpp \
    hotelpolicies.cpp \
    joinapplication.cpp \
    license.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    platform.cpp \
    platformadministrator.cpp \
    rangeslider.cpp \
    registerwindow.cpp \
    resetpassworddialog.cpp \
    room.cpp

HEADERS += \
    abstractbooking.h \
    abstractuser.h \
    administratortab.h \
    amenities.h \
    btripdatabase.h \
    business.h \
    customer.h \
    customertab.h \
    detaildialog.h \
    hotel.h \
    hotelapplicationstep.h \
    hotelbooking.h \
    hotelmanaertab.h \
    hotelmanager.h \
    hotelpolicies.h \
    joinapplication.h \
    license.h \
    loginwindow.h \
    mainwindow.h \
    platform.h \
    platformadministrator.h \
    rangeslider.h \
    registerwindow.h \
    resetpassworddialog.h \
    room.h

FORMS += \
        mainwindow.ui \
    administratortab.ui \
    customertab.ui \
    detaildialog.ui \
    hotelapplicationstep.ui \
    hotelmanaertab.ui \
    loginwindow.ui \
    mainwindow.ui \
    registerwindow.ui \
    resetpassworddialog.ui

RESOURCES += \
    icon.qrc

