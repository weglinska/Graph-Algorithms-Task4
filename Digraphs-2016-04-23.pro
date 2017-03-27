TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    directedgraph.h \
    undirectedgraph.h \
    consistent.h \
    vertex.h \
    consistentgraphgenerator.h \
    maxstronglyconnectedcomponent.h \
    dag.h \
    topologicalsort.h \
    shortestpaths.h

SOURCES += \
    directedgraph.cpp \
    undirectedgraph.cpp \
    consistent.cpp \
    vertex.cpp \
    consistentgraphgenerator.cpp \
    maxstronglyconnectedcomponent.cpp \
    dag.cpp \
    topologicalsort.cpp \
    shortestpaths.cpp

