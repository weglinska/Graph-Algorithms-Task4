#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <cstdlib>
#include <vector>

struct Connection {
    int firstID;
    int secondID;
    int weight;
    int distance;

    int getMax()const {
        return ((firstID > secondID) ? firstID : secondID);
    }
    int getWeight()const {
        return weight;
    }
    int getDistance()const {
        return weight;
    }
};

class Graph {
private:
    int _verticesNumber;
    bool** _adjacencyMatrix;
    int** _weightMatrix;
    int** _distanceMatrix;
    static int _maxWeight;
public:
    static Graph* pointSideGenerator(const int n, const int l);
    static Graph* copyFromAdjancencyList(std::vector<std::vector<int> > adjancencyList);
    static Graph* pointProbabilityGenerator(const int n, const double p);
    static Graph* copyFromConnectionList(std::vector<Connection> connectionList);
    static Graph* copyFromConnectionMatrix(std::vector<std::vector<bool> > connectionMatrix);
    static int getMaxWeight();

    Graph(int size);
    Graph(bool** Matrix, const int number);
    ~Graph();
    int getVerticesNumber();
    bool * operator [](int pos);
    void connectVertices(int firstID, int secondID, int weight=0);
    void disconnectVertices(int firstID, int secondID);
    bool getAdjacencyMatrixValue(int firstID, int secondID);
    std::vector<std::vector<int> > getAdjacencyList();
    void printAdjacencyList();
    void printAdjacencyMatrix();
    std::vector<Connection> getConnectionList();
    std::vector<std::vector<bool> > getConnectionMatrix();
    bool** getAdjacencyMatrix() const;
    int getDistance(int firstID, int secondID);
    int getWeight(int firstID, int secondID) const;
    int** getWeightMatrix() const;
    int** getDistanceMatrix() const;
    void setConnectionWeight(int firstID, int secondID, int weight);
    void updateDistanceMatrix();
    void printWeightMatrix() const;
};

#endif // GRAPH_H
