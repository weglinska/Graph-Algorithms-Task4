#ifndef CONSISTENTGRAPHGENERATOR_H
#define CONSISTENTGRAPHGENERATOR_H
#include <iostream>
#include "undirectedgraph.h"
#include "consistent.h"

class ConsistentGraphGenerator
{
private:
    ConsistentGraphGenerator();
public:
    // losowy graf spojny - zadanie 1
    static Graph* randomConsistentGraph(const int verticesNumber);
};

#endif // CONSISTENTGRAPHGENERATOR_H
