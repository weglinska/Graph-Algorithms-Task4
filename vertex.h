#ifndef VERTEX_H
#define VERTEX_H
#include <vector>
#include <queue>


enum VertexColor { WHITE, GRAY, BLACK };

class Vertex
{
private:
    int _id;
    VertexColor _color;
    std::vector<Vertex*> _adjacencyArray;
public:
    Vertex();
    int GetID() const;
    VertexColor GetColor() const;
    int GetAdjacencyNumber() const;
    Vertex* GetAdjacentVertex(const int index) const;
    void SetID(const int id);
    void SetColor(const VertexColor color);
    void AddToAjacencyArray(Vertex* vertex);
};

#endif // VERTEX_H
