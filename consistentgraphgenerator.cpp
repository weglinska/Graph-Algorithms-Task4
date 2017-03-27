#include "consistentgraphgenerator.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

ConsistentGraphGenerator::ConsistentGraphGenerator() {}

Graph* ConsistentGraphGenerator::randomConsistentGraph(const int verticesNumber)
{
    int edgesNumber = ((verticesNumber>=2) ? rand()%(verticesNumber*(verticesNumber-1)/2)+1 : 0);

    Graph* randomConsistentGraph = Graph::pointSideGenerator(verticesNumber, edgesNumber);

    bool** adjacencyMatrix = randomConsistentGraph->getAdjacencyMatrix();
    std::vector<int> consistentVector;

    consistentVector = Consistent::getMaxConsistent(adjacencyMatrix, verticesNumber);
    unsigned int consistentVectorSize = consistentVector.size();

    for(int i=0; i<verticesNumber; i++)
    {
        unsigned int indexToConnect = rand()%consistentVectorSize;
        randomConsistentGraph->connectVertices(i, consistentVector[indexToConnect]-1);
    }

    for(int i=0; i<verticesNumber; i++)
        for(int j=i; j<verticesNumber; j++)
            randomConsistentGraph->setConnectionWeight(i, j, rand()%Graph::getMaxWeight()+1);

    return randomConsistentGraph;
}
