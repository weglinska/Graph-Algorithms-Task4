#include "engine.h"

Engine::Engine(QObject *parent)
{
    graph=NULL;
}

DirectedGraph * Engine::getGraph(){
    return graph;
}

void Engine::removeGraph(){
    if(graph){
        delete graph;
    }
}

void Engine::setGraph(DirectedGraph * graph){
    removeGraph();
    this->graph=graph;
    emit updateGraph();
}

void Engine::changeGraphSize(int newSize){
    removeGraph();
    graph=new DirectedGraph(newSize);
    emit updateGraph();
}

Engine * Engine::engine=NULL;

Engine::Engine(const Engine &en){}


void Engine::updateGraph(QObject * sender){
    emit changedGraph(sender);
}
