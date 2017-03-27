#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include "undirectedgraph.h"
#include "consistentgraphgenerator.h"

/**
 * @brief The DiConnection struct
 * struktura opisuje skierowana krawedz (luk)
 * firstID = wierzcholek poczatkowy
 * secondID = wierzholek koncowy
 */
struct DiConnection {
    int firstID;
    int secondID;
};

/**
 * @brief The DirectedGraph class
 * klasa sluzy do kodowania grafow skierowanych
 * korzysta z klas: Graph i ConsistentGraphGenerator
 * realizuje zadanie nr 1 z IV zestawu
 */
class DirectedGraph {
public:
    int _verticesNumber;
    bool** _adjacencyMatrix;
    int** _weightMatrix;
    int** _distanceMatrix;

public:
    // konstruktor generuje graf pusty o verticesNumber wierzcholkach
    DirectedGraph(int verticesNumber);
    // ten konstruktor kopiuje graf nieskierowany i LOSUJE polaczenia
    DirectedGraph(Graph* undirectedGraph);
    DirectedGraph(bool** adjacencyMatrix, int verticesNumber);
    DirectedGraph(int** weightMatrix, int verticesNumber);
    ~DirectedGraph();
    int getVerticesNumber() const;
    bool** getAdjacencyMatrix() const;
    int** getWeightMatrix() const;
    int** getDistanceMatrix() const;
    int getWeight(int firstID, int secondID) const;
    bool* operator [](int pos);
    int getVertexDegree(const int vertexNumber) const;
    std::vector<std::vector<int> > getAdjacencyList() const;
    std::vector<DiConnection> getDiConnectionList() const;
    std::vector<std::vector<int> > getIncidenceMatrix() const;
    std::vector<std::vector<int> > getCycles() const;
    bool getCyclesRecursive(int vStart, int wCurrent, std::vector<int>* stack, bool visited[]) const;
    std::vector<std::vector<int> > getStronglyConnectedComponents() const;
    void getStronglyConnectedComponentsRecursive(int vertex, bool visited[], std::vector<int>* stack) const;
    std::vector<int>* collectStronglyConnectedComponentsRecursive(int vertex, bool visited[], std::vector<int>* componentTmp, bool** tMatrix) const;
    void printAdjacencyMatrix() const;
    static DirectedGraph* randomConsistentDiGraph(const int verticesNumber);
    static DirectedGraph* copyDirectedGraph(const DirectedGraph* diGraphToCopy);
    void printAdjacencyList();
    void printDistanceMatrix() const;
    void printWeightMatrix() const;
    void changeAdjacencyMatrixValue(const int i, const int j);

};

#endif // DIRECTEDGRAPH_H //
