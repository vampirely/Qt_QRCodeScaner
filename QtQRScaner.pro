#-------------------------------------------------
#
# Project created by QtCreator 2022-07-21T14:39:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtQRScaner
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
        MainWindow.cpp \
    ScreenWidget.cpp



HEADERS += \
        MainWindow.h \
    ScreenWidget.h


FORMS += \
        MainWindow.ui

RESOURCES += \
    images.qrc


win32: LIBS += -L$$PWD/libs/ -lQZXing3

INCLUDEPATH += $$PWD/libs/include
DEPENDPATH += $$PWD/libs/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libs/QZXing3.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/libs/libQZXing3.a
