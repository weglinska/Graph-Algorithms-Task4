#include "maxstronglyconnectedcomponent.h"
#include <ctime>
#include "shortestpaths.h"
#define INF 9999999

MaxStronglyConnectedComponent::MaxStronglyConnectedComponent() {}

DirectedGraph* MaxStronglyConnectedComponent::getMaxStronglyConnectedComponent(DirectedGraph* diGraphTmp) {
    srand((unsigned int)time(NULL));
    std::vector<std::vector<int> > diComponents = diGraphTmp->getStronglyConnectedComponents();
    std::vector<int> maxComponent; unsigned int maxSize = 0;
    for(unsigned int i=0; i<diComponents.size(); i++)
        if(diComponents[i].size() > maxSize) {
            maxSize = diComponents[i].size();
            maxComponent = diComponents[i];
        }

    DirectedGraph* diGraph = new DirectedGraph(diGraphTmp->getVerticesNumber());
    for(unsigned int i=0; i<maxComponent.size(); i++) {
        int u = maxComponent[i];
        for(unsigned int j=0; j<maxComponent.size(); j++) {
            int v = maxComponent[j];
            if(diGraphTmp->getAdjacencyMatrix()[u-1][v-1] == true)
                diGraph->getAdjacencyMatrix()[u-1][v-1] = true;
        }
    }

    do
    {
        for(int i=0; i<diGraph->getVerticesNumber(); i++)
            for(int j=0; j<diGraph->getVerticesNumber(); j++)
                if(diGraph->getAdjacencyMatrix()[i][j] == true)
                    diGraph->getWeightMatrix()[i][j] = rand()%26 - 5;
    }
    while(hasNegativeCycle(diGraph));

    return diGraph;
}

bool MaxStronglyConnectedComponent::hasNegativeCycle(DirectedGraph* diGraph) {

    // wersja Romana
    /*std::vector<std::vector<int> > cycles = diGraph->getCycles();
    int** weightMatrix = diGraph->getWeightMatrix();
    for(unsigned int i=0; i<cycles.size(); i++) {
        int sum = 0;
        for(unsigned int j=0; j<cycles[i].size()-1; j++) {
            sum += weightMatrix[cycles[i][j]-1][cycles[i][j+1]-1];
        }
        if(sum<0) return true;
    }
    return false;*/

    // głupia wersja
    /*int size=diGraph->getVerticesNumber();
    ShortestPaths::johnson(diGraph);
    int **distances=diGraph->getDistanceMatrix();
    for (int i=0; i<size; ++i)
        if (distances[i][i]!=0)
            return true;

   ShortestPaths::floydWarshall(diGraph);
   for (int i=0; i<size; ++i)
       if (distances[i][i]!=0)
           return true;

    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
            distances[i][j]=0;
    return false;*/

    // wersja z bellmanem-fordem
    int size=diGraph->getVerticesNumber();
    int **weights=diGraph->getWeightMatrix();
    bool **adjacency=diGraph->getAdjacencyMatrix();

    for (int s=0; s<size; ++s)
    {

        int d[size];
        for (int i=0; i<size; ++i)
        {
            d[i]=INF;
        }
        d[s]=0;

        for (int k=0; k<size; ++k)
        {
            for (int i=0; i<size; ++i)
            {
                for (int j=0; j<size; ++j)
                {
                    if (d[i]>d[j]+weights[i][j] && d[j]!=INF && weights[i][j]!=INF && adjacency[i][j])
                    {
                        d[i]=d[j]+weights[i][j];
                    }
                }
            }

        }

        for (int k=0; k<size; ++k)
        {
            for (int i=0; i<size; ++i)
            {
                for (int j=0; j<size; ++j)
                {
                    if (d[i]>d[j]+weights[i][j] && d[j]!=INF && weights[i][j]!=INF && adjacency[i][j])
                    {
                        return true;
                    }
                }
            }

        }
    }

    return false;


}

bool MaxStronglyConnectedComponent::getDistances(DirectedGraph* diGraph, unsigned int sVertex, std::vector<int>& distances) {
    const unsigned int vNumber = diGraph->getVerticesNumber();
    if(vNumber==0) return false;
    if(sVertex > vNumber-1) sVertex = vNumber-1;
    std::vector<int> previous;
    int** weightMatrix = diGraph->getWeightMatrix(); bool test;
    std::vector<std::vector<int> > adjList = diGraph->getAdjacencyList();
        for(unsigned int i=0; i<vNumber; i++) {
            distances.push_back(INF);
            previous.push_back(-1);
        }
        distances[sVertex] = 0;
        for(unsigned int i=2; i<=vNumber; i++) {
            test = true;
            for(unsigned int x=0; x<vNumber; x++) {
                for(unsigned int j=0; j<adjList[x].size(); j++) {
                    unsigned int y = adjList[x][j];
                    if(distances[y]<=distances[x]+weightMatrix[x][y]) continue;
                    test = false;
                    distances[y] = distances[x] + weightMatrix[x][y];
                    previous[y] = x;
                }
            if(test==true) return true;
            }
        }
        for(unsigned int x=0; x<vNumber; x++)
            for(unsigned int j=0; j<adjList[x].size(); j++) {
                unsigned int y = adjList[x][j];
                if(distances[y]>distances[x]+weightMatrix[x][y]) {
                    return false;
                }
            }
    return true;
}
