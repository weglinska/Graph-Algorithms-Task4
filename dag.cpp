#include "dag.h"

DirectedGraph* DirectedAcyclicGraph::dagCreator(DirectedGraph* graph)
{

	srand(time(NULL));

	DirectedGraph* newGraph = DirectedGraph::copyDirectedGraph(graph);

	std::vector<std::vector<int> > cycles = newGraph->getCycles();
	
	while(cycles.empty() == false){

		std::vector<int> cycle = cycles[0];

		int i = rand()%(int)(cycle.size() - 1);

        newGraph->changeAdjacencyMatrixValue(cycle[i]-1, cycle[i+1]-1);

		cycles.clear();
		cycles = newGraph->getCycles();

	}

	return newGraph;

}

