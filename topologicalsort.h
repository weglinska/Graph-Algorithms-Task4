#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <iostream>
#include <vector>
#include <list>
#include "directedgraph.h"

class TopologicalSort
{
	public:
		static std::list<int> getTopologicalSort(DirectedGraph* graph);
		static void dfs(int verticesNumber, std::vector<bool>& visitedVertices, std::vector<std::vector<int> > adjacencyMatrix, std::list<int>& topologicalOrder);
		static void dfsUtil(int vertex, std::vector<bool>& visitedVertices, std::vector<std::vector<int> > adjacencyMatrix, std::list<int>& topologicalOrder);
};

#endif