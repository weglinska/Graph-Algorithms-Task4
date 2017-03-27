#ifndef ENGINE_H
#define ENGINE_H
#include <QObject>
#include <QTimer>
#include <vector>
#include "directedgraph.h"
class Engine: public QObject
{
    Q_OBJECT
public:

    DirectedGraph * graph;
    static Engine * engine;
    static Engine * getInstance(){
        if(engine==NULL){
            engine=new Engine();
        }
        return engine;
    }
    DirectedGraph * getGraph();
    void removeGraph();
private:
    explicit Engine(QObject *parent = 0);
    Engine(const Engine & en);

signals:
    void changedGraph(QObject * sender);
public slots:
    void updateGraph(QObject * sender = NULL);
    void changeGraphSize(int newSize);
    void setGraph(DirectedGraph *);

};

#endif // ENGINE_H
