#include "consistent.h"
#include <iostream>


Consistent::Consistent(bool** adjacencyMatrix, const int verticesNumber)
{
    for(int i = 1; i <= verticesNumber; i++)
    {
        Vertex* vertex = new Vertex();
        vertex->SetID(i);
        this->_adjacencyList.push_back(vertex);
    }

    for(int i=0; i<verticesNumber; i++)
    {
        for(int j=i; j<verticesNumber; j++)
        {
            if(adjacencyMatrix[i][j] == true)
            {
                Vertex* u = this->_adjacencyList[i];
                Vertex* v = this->_adjacencyList[j];

                u->AddToAjacencyArray(v);
                v->AddToAjacencyArray(u);
            }
        }
    }

    Vertex* vertexS;

    for(int i=0; i<verticesNumber; i++)
    {
        std::vector<int> currentConsistent;
        Vertex* vertexX = this->_adjacencyList[i];
        if(vertexX->GetColor() == WHITE)
        {
            vertexS = vertexX;
            vertexS->SetColor(GRAY);
            std::queue<Vertex*> vertexQueue;
            vertexQueue.push(vertexS);
            while(vertexQueue.size() != 0)
            {
               Vertex* vertexU = vertexQueue.front();
               for(int j=0; j<vertexU->GetAdjacencyNumber(); j++)
               {
                    Vertex* vertexV = vertexU->GetAdjacentVertex(j);
                    if(vertexV->GetColor() == WHITE)
                    {
                        vertexV->SetColor(GRAY);
                        vertexQueue.push(vertexV);
                    }
               }
               vertexQueue.pop();
               vertexU->SetColor(BLACK);
               currentConsistent.push_back(vertexU->GetID());
            }
        }
        if(this->getMaxConsistentArray().size() < currentConsistent.size())
        {
            this->_maxConsistentArray = currentConsistent;
        }
    }
}

std::vector<int> Consistent::getMaxConsistentArray() const
{
    return this->_maxConsistentArray;
}

std::vector<int> Consistent::getMaxConsistent(bool** adjacencyMatrix, const int verticesNumber)
{
    Consistent consistent(adjacencyMatrix, verticesNumber);
    return consistent.getMaxConsistentArray();
}
