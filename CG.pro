#-------------------------------------------------
#
# Project created by QtCreator 2021-05-28T18:07:06
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = CG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    trackball.cpp \
    camera.cpp \
    light.cpp \
    material.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    trackball.h \
    camera.h \
    light.h \
    material.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
