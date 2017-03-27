#-------------------------------------------------
#
# Project created by QtCreator 2016-04-23T17:46:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = grafy4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vertex.cpp \
    undirectedgraph.cpp \
    topologicalsort.cpp \
    maxstronglyconnectedcomponent.cpp \
    directedgraph.cpp \
    dag.cpp \
    consistentgraphgenerator.cpp \
    consistent.cpp \
    engine.cpp \
    matrixvievcell.cpp \
    matrixview.cpp \
    listviewremovebutton.cpp \
    listviewitem.cpp \
    listview.cpp \
    addconnection.cpp \
    connectionmatrixview.cpp \
    graphpainter.cpp \
    shortestpaths.cpp \
    distancematrix.cpp

HEADERS  += mainwindow.h \
    vertex.h \
    undirectedgraph.h \
    topologicalsort.h \
    maxstronglyconnectedcomponent.h \
    directedgraph.h \
    dag.h \
    consistentgraphgenerator.h \
    consistent.h \
    engine.h \
    matrixvievcell.h \
    matrixview.h \
    listviewremovebutton.h \
    listviewitem.h \
    listview.h \
    addconnection.h \
    connectionmatrixview.h \
    graphpainter.h \
    shortestpaths.h \
    distancematrix.h

FORMS    += mainwindow.ui \
    addconnection.ui

SUBDIRS += \
    Digraphs-2016-04-23.pro

DISTFILES += \
    grafy4.pro.user \
    README.md
