#include "directedgraph.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

DirectedGraph::DirectedGraph(int verticesNumber) {
    this->_verticesNumber = verticesNumber;
    this->_adjacencyMatrix = new bool*[this->_verticesNumber];
         for(int i=0; i<this->_verticesNumber; i++) {
            this->_adjacencyMatrix[i] = new bool[this->_verticesNumber];
            for(int j=0; j<this->_verticesNumber; j++)
                this->_adjacencyMatrix[i][j] = false;
         }

    this->_weightMatrix = new int*[this->_verticesNumber];
    for(int i=0; i<this->_verticesNumber; i++) {
        this->_weightMatrix[i] = new int[this->_verticesNumber];
        for(int j=0; j<this->_verticesNumber; j++)
            this->_weightMatrix[i][j] = 0;
    }

    _distanceMatrix=new int* [_verticesNumber];
    for(int i=0;i<_verticesNumber;i++){
        _distanceMatrix[i]=new int[_verticesNumber];
        for(int j=0;j<_verticesNumber;j++){
            _distanceMatrix[i][j]=0;
        }
    }
}

DirectedGraph::DirectedGraph(Graph* undirectedGraph) {
    srand((unsigned int)time(NULL));
    this->_verticesNumber = undirectedGraph->getVerticesNumber();

    bool** adjacencyMatrixUG = undirectedGraph->getAdjacencyMatrix();
    this->_adjacencyMatrix = new bool*[this->_verticesNumber];
         for(int i=0; i<this->_verticesNumber; i++) {
            this->_adjacencyMatrix[i] = new bool[this->_verticesNumber];
            for(int j=0; j<this->_verticesNumber; j++)
                this->_adjacencyMatrix[i][j] = adjacencyMatrixUG[i][j];
         }

    this->_weightMatrix = new int*[this->_verticesNumber];
    for(int i=0; i<this->_verticesNumber; i++) {
        this->_weightMatrix[i] = new int[this->_verticesNumber];
        for(int j=0; j<this->_verticesNumber; j++)
            this->_weightMatrix[i][j] = 0;
    }

    _distanceMatrix=new int* [_verticesNumber];
    for(int i=0;i<_verticesNumber;i++){
        _distanceMatrix[i]=new int[_verticesNumber];
        for(int j=0;j<_verticesNumber;j++){
            _distanceMatrix[i][j]=0;
        }
    }

    for(int i=0; i<this->_verticesNumber; i++)
        for(int j=i; j<this->_verticesNumber; j++)
            if(this->_adjacencyMatrix[i][j] == true) {
                int random = rand()%3;
                if(random == 1)
                    this->_adjacencyMatrix[i][j] = false;
                else if(random == 2)
                    this->_adjacencyMatrix[j][i] = false;
            }
}

DirectedGraph::DirectedGraph(bool** adjacencyMatrix, int verticesNumber): _verticesNumber(verticesNumber), _adjacencyMatrix(adjacencyMatrix){
	_weightMatrix=new int* [_verticesNumber];
    for(int i=0;i<_verticesNumber;i++){
        _weightMatrix[i]=new int[_verticesNumber];
        for(int j=0;j<_verticesNumber;j++){
                _weightMatrix[i][j]=0;
        }
    }

    _distanceMatrix=new int* [_verticesNumber];
    for(int i=0;i<_verticesNumber;i++){
        _distanceMatrix[i]=new int[_verticesNumber];
        for(int j=0;j<_verticesNumber;j++){
            _distanceMatrix[i][j]=0;
        }
    }
}

DirectedGraph::DirectedGraph(int** weightMatrix, int verticesNumber){

    this->_verticesNumber = verticesNumber;
    _weightMatrix=weightMatrix;

    _distanceMatrix=new int* [_verticesNumber];
    for(int i=0;i<_verticesNumber;i++){
        _distanceMatrix[i]=new int[_verticesNumber];
        for(int j=0;j<_verticesNumber;j++){
            _distanceMatrix[i][j]=0;
        }
    }
        this->_adjacencyMatrix = new bool*[this->_verticesNumber];
         for(int i=0; i<this->_verticesNumber; i++) {
            this->_adjacencyMatrix[i] = new bool[this->_verticesNumber];
            for(int j=0; j<this->_verticesNumber; j++)
            {
                if (weightMatrix[i][j])
                    this->_adjacencyMatrix[i][j]=true;
                else
                    this->_adjacencyMatrix[i][j]=false;

            }
         }


}


DirectedGraph::~DirectedGraph() {
    for(int i=0; i<this->_verticesNumber; i++)
        delete [] this->_adjacencyMatrix[i];
    delete [] this->_adjacencyMatrix;

    for(int i=0; i<this->_verticesNumber; i++)
        delete [] this->_weightMatrix[i];
    delete [] this->_weightMatrix;

    for(int i=0; i<this->_verticesNumber; i++)
        delete [] this->_distanceMatrix[i];
    delete [] this->_distanceMatrix;
}

int DirectedGraph::getVerticesNumber() const {
    return this->_verticesNumber;
}

bool** DirectedGraph::getAdjacencyMatrix() const {
    return this->_adjacencyMatrix;
}

int** DirectedGraph::getWeightMatrix() const {
    return this->_weightMatrix;
}

int** DirectedGraph::getDistanceMatrix() const {
    return this->_distanceMatrix;
}

bool* DirectedGraph::operator [](int pos) {
    return this->_adjacencyMatrix[pos];
}

int DirectedGraph::getVertexDegree(const int vertexNumber) const {
    int degree = 0;
    for(int j=0; j<this->_verticesNumber; j++)
        if(this->_adjacencyMatrix[vertexNumber][j] == true)
            degree ++;
    return degree;
}

int DirectedGraph::getWeight(int firstID, int secondID) const

{

    return this->_weightMatrix[firstID][secondID];

}

std::vector<std::vector<int> > DirectedGraph::getAdjacencyList() const {
    std::vector<std::vector<int> > adjancencyList;
    for(int i=0; i<_verticesNumber; i++)
    {
            adjancencyList.push_back(std::vector<int>());
            for(int j=0; j<this->_verticesNumber; j++){
                if(this->_adjacencyMatrix[i][j] == true){
                    adjancencyList[i].push_back(j);
                }
            }
    }
    return adjancencyList;
}

std::vector<DiConnection> DirectedGraph::getDiConnectionList() const {
    std::vector<DiConnection> connections;
    for(int i=0; i<_verticesNumber; i++)
        for(int j=0;j<_verticesNumber;j++)
            if(this->_adjacencyMatrix[i][j]) {
                DiConnection conn={i,j};
                connections.push_back(conn);
            }
    return connections;
}

std::vector<std::vector<int> > DirectedGraph::getIncidenceMatrix() const {
    std::vector<DiConnection> connectionMap=getDiConnectionList();
    std::vector<std::vector<int> > matrix =
            std::vector<std::vector<int> >(connectionMap.size(),std::vector<int>(_verticesNumber,0));

    for(unsigned i=0; i<connectionMap.size(); i++) {
        matrix[i][connectionMap[i].firstID]=1;
        matrix[i][connectionMap[i].secondID]=-1;
    }
    return matrix;
}

std::vector<std::vector<int> > DirectedGraph::getCycles() const {
    std::vector<std::vector<int> > cycles;
    int vNumber = this->getVerticesNumber();
    bool* visited = new bool[vNumber];
    std::vector<int>* stack = new std::vector<int>();
    for(int i=0; i<vNumber; i++) {
        for(int j=0; j<vNumber; j++) visited[j] = false;
        if(this->getCyclesRecursive(i, i, stack, visited) == false) continue;
        std::vector<int> cycle;
        cycle.push_back(i+1);
        while(stack->empty() == false) {
            cycle.push_back(stack->back()+1);
            stack->pop_back();
        }
        std::reverse(cycle.begin(), cycle.end());
        cycles.push_back(cycle);
    }
    delete [] visited;
    delete stack;
    return cycles;
}

bool DirectedGraph::getCyclesRecursive(int vStart, int wCurrent, std::vector<int>* stack, bool visited[]) const {
    visited[wCurrent] = true;
    stack->push_back(wCurrent);
    for(int j=0; j<this->getVerticesNumber(); j++)
        if((this->_adjacencyMatrix[wCurrent][j]) == true) {
            if(j == vStart) return true;
            if((visited[j] == false) && (this->getCyclesRecursive(vStart, j, stack, visited))) return true;
        }
    stack->pop_back();
    return false;
}

std::vector<std::vector<int> > DirectedGraph::getStronglyConnectedComponents() const {
    std::vector<std::vector<int> > components;
    const int vNumber = this->getVerticesNumber();
    bool* visited = new bool[vNumber];
    for(int i=0; i<vNumber; i++)
        visited[i] = false;
    std::vector<int>* stack = new std::vector<int>();
    for(int vertex=0; vertex<vNumber; vertex++) {
        if(visited[vertex] == false)
            this->getStronglyConnectedComponentsRecursive(vertex, visited, stack);
    }
    bool** tMatrix = new bool*[vNumber];
    for(int i=0; i<vNumber; i++) {
        tMatrix[i] = new bool[vNumber];
        for(int j=0; j<vNumber; j++)
            tMatrix[i][j] = this->_adjacencyMatrix[j][i];
    }
    for(int i=0; i<vNumber; i++)
        visited[i] = false;
    int counter = 0;
    while(stack->empty() == false) {
        int vertex = stack->back();
        stack->pop_back();
        if(visited[vertex] == true) continue;
        counter ++;
        std::vector<int>* componentTmp = new std::vector<int>();
        this->collectStronglyConnectedComponentsRecursive(vertex, visited, componentTmp, tMatrix);
        std::vector<int> component(*componentTmp);
        components.push_back(component);
        delete componentTmp;
    }
    delete [] visited;
    delete stack;
    return components;
}

void DirectedGraph::getStronglyConnectedComponentsRecursive(int vertex, bool visited[], std::vector<int>* stack) const {
    const int vNumber = this->getVerticesNumber();
    visited[vertex] = true;
    for(int uVertex=0; uVertex<vNumber; uVertex++) {
        if(this->_adjacencyMatrix[vertex][uVertex] == true)
            if(visited[uVertex] == false)
                this->getStronglyConnectedComponentsRecursive(uVertex, visited, stack);
    }
    stack->push_back(vertex);
}

std::vector<int>* DirectedGraph::collectStronglyConnectedComponentsRecursive(int vertex, bool visited[], std::vector<int>* componentTmp, bool** tMatrix) const {
    const int vNumber = this->getVerticesNumber();
    visited[vertex] = true;
    componentTmp->push_back(vertex+1);
    for(int uVertex=0; uVertex<vNumber; uVertex++) {
        if(tMatrix[vertex][uVertex] == true)
            if(visited[uVertex] == false)
                this->collectStronglyConnectedComponentsRecursive(uVertex, visited, componentTmp, tMatrix);
    }
    return componentTmp;
}

void DirectedGraph::printAdjacencyMatrix() const {
    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << i+1 << " ";
    std::cout << std::endl;

    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << "__";
    std::cout << std::endl;

    for(int i=0; i<this->_verticesNumber; i++) {
        std::cout << i+1 << " |";
        for(int j=0; j<this->_verticesNumber; j++)
            std::cout << (this->_adjacencyMatrix[i][j] == true ? 1 : 0) << " ";
        std::cout << std::endl;
    }
}

void DirectedGraph::printWeightMatrix() const
{
    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << i+1 << " ";
    std::cout << std::endl;

    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << "__";
    std::cout << std::endl;

    for(int i=0; i<this->_verticesNumber; i++)
    {
        std::cout << i+1 << " |";
        for(int j=0; j<this->_verticesNumber; j++)
            std::cout << (this->_weightMatrix[i][j]) << " ";
        std::cout << std::endl;
    }
}

void DirectedGraph::printDistanceMatrix() const
{
    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << i+1 << " ";
    std::cout << std::endl;

    std::cout << "   ";
    for(int i=0; i<this->_verticesNumber; i++)
        std::cout << "__";
    std::cout << std::endl;

    for(int i=0; i<this->_verticesNumber; i++)
    {
        std::cout << i+1 << " |";
        for(int j=0; j<this->_verticesNumber; j++)
            std::cout << (this->_distanceMatrix[i][j]) << " ";
        std::cout << std::endl;
    }
}

DirectedGraph* DirectedGraph::randomConsistentDiGraph(const int verticesNumber) {
    Graph* undirectedGraph =
            ConsistentGraphGenerator::randomConsistentGraph(verticesNumber);
    return new DirectedGraph(undirectedGraph);
}

DirectedGraph* DirectedGraph::copyDirectedGraph(const DirectedGraph* diGraphToCopy) {
    DirectedGraph* diGraph = new DirectedGraph(diGraphToCopy->getVerticesNumber());
    const int vNumber = diGraph->getVerticesNumber();
    for(unsigned int i=0; i<vNumber; i++)
        for(unsigned int j=0; j<vNumber; j++) {
            diGraph->getAdjacencyMatrix()[i][j] = diGraphToCopy->getAdjacencyMatrix()[i][j];
            diGraph->getWeightMatrix()[i][j] = diGraphToCopy->getWeightMatrix()[i][j];
        }
    return diGraph;
}

void DirectedGraph::printAdjacencyList()
{
    for(int i=0; i<this->_verticesNumber; i++)
    {
        std::cout << i+1 << ": ";
        for(int j=0; j<this->_verticesNumber; j++)
            if(this->_adjacencyMatrix[i][j] == true)
                std::cout << j+1 << " ";
        std::cout << std::endl;
    }
}

void DirectedGraph::changeAdjacencyMatrixValue(const int i, const int j)
{
    _adjacencyMatrix[i][j] = false;
}
