#ifndef SHORTESTPATHS_H
#define SHORTESTPATHS_H
#include "directedgraph.h"


class ShortestPaths
{
public:
    ShortestPaths();
    static void floydWarshall(DirectedGraph* graph);
    static void johnson(DirectedGraph* dgraph);
    static int bellmanFord(DirectedGraph* graph, int s, int w);
    static void dijkstry(DirectedGraph* graph, int source);



};

#endif // SHORTESTPATHS_H
