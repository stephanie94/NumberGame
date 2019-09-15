QT       = core gui
%NETWORK%QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
SOURCES += main.cpp \
    buttondialog.cpp \
    buttonengine.cpp \
    buttonpresentation.cpp

HEADERS += \
    buttondialog.h \
    buttonengine.h \
    buttonpresentation.h

RESOURCES += \
    resources.qrc
