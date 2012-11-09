#-------------------------------------------------
#
# Project created by QtCreator 2012-11-05T07:55:32
#
#-------------------------------------------------

QT       -= gui
QT       += network


CONFIG(debug, debug|release){
    TARGET = CSqld

    LIBS += -L../ctcpclient/debug -lctcpclientd
}
CONFIG(release, debug|release){
    TARGET = CSql

    LIBS += -L../ctcpclient/release -lctcpclient
}

TEMPLATE = lib

DEFINES += CSQL_LIBRARY

SOURCES += csql.cpp

HEADERS += csql.h\
        CSql_global.h

DEPENDPATH += ../ctcpclient

INCLUDEPATH += ../ctcpclient
