#ifndef CONSISTENT_H
#define CONSISTENT_H
#include <vector>
#include "vertex.h"


class Consistent
{
private:
    bool** _adjacencyMatrix;
    std::vector<Vertex*> _adjacencyList;
    std::vector<int> _maxConsistentArray;
public:
    Consistent(bool** adjacencyMatrix, const int verticesNumber);
    std::vector<int> getMaxConsistentArray() const;
    static std::vector<int> getMaxConsistent(bool** adjacencyMatrix, const int verticesNumber);
};

#endif // CONSISTENT_H
