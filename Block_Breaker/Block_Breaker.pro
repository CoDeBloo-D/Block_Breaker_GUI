#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T16:15:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Block_Breaker
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

CONFIG += c++11

SOURCES += \
        ball.cpp \
        block.cpp \
        board.cpp \
        difficulty.cpp \
        gamewindow.cpp \
        help.cpp \
        main.cpp \
        mainwindow.cpp \
        stage.cpp

HEADERS += \
        ball.h \
        block.h \
        board.h \
        difficulty.h \
        gamewindow.h \
        help.h \
        mainwindow.h \
        stage.h

FORMS += \
        difficulty.ui \
        help.ui \
        mainwindow.ui \
        stage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc

DISTFILES +=
