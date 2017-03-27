#ifndef DAG_H
#define DAG_H

#include "directedgraph.h"
#include <vector>
#include <ctime>

/*
	klasa służąca do zmiany digrafu w digraf acykliczny
*/

class DirectedAcyclicGraph
{
	public:
		//metoda usuwa losową krawędź w każdym ze znalezionych cyklów
		static DirectedGraph* dagCreator(DirectedGraph* graph);
};

#endif