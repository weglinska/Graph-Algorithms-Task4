#include "vertex.h"


Vertex::Vertex() : _color(WHITE)
{

}

int Vertex::GetID() const
{
    return this->_id;
}

VertexColor Vertex::GetColor() const
{
    return this->_color;
}

int Vertex::GetAdjacencyNumber() const
{
    return this->_adjacencyArray.size();
}

Vertex* Vertex::GetAdjacentVertex(const int index) const
{
    return this->_adjacencyArray[index];
}

void Vertex::SetID(const int id)
{
    this->_id = id;
}

void Vertex::SetColor(const VertexColor color)
{
    this->_color = color;
}

void Vertex::AddToAjacencyArray(Vertex* vertex)
{
    this->_adjacencyArray.push_back(vertex);
}
