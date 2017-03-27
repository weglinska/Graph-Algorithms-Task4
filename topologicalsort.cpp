#include "topologicalsort.h"

void TopologicalSort::dfsUtil(int vertex, std::vector<bool>& visitedVertices, std::vector<std::vector<int> > adjacencyList, std::list<int>& topologicalOrder)
{
	visitedVertices[vertex] = true;
	std::vector<int> adjacentVertices = adjacencyList[vertex];

	for(unsigned i=0; i<adjacentVertices.size(); i++)
	{
		if(!visitedVertices[adjacentVertices[i]]){ 
			TopologicalSort::dfsUtil(adjacentVertices[i], visitedVertices, adjacencyList, topologicalOrder);
		}
	}
	topologicalOrder.push_front(vertex);
}

void TopologicalSort::dfs(int verticesNumber, std::vector<bool>& visitedVertices, std::vector<std::vector<int> > adjacencyList, std::list<int>& topologicalOrder)
{
	for(int i=0; i<verticesNumber; i++)
	{

		if(!visitedVertices[i])
			TopologicalSort::dfsUtil(i, visitedVertices, adjacencyList, topologicalOrder);
		
	}
}

std::list<int> TopologicalSort::getTopologicalSort(DirectedGraph* graph)
{

	int verticesNumber = graph->getVerticesNumber();
	std::vector<std::vector<int> > adjacencyList = graph->getAdjacencyList();

	std::vector<bool> visitedVertices(verticesNumber);
	std::list<int> topologicalOrder;

	if(topologicalOrder.empty())
	{
		TopologicalSort::dfs(verticesNumber, visitedVertices, adjacencyList, topologicalOrder);
	}

	return topologicalOrder;
}