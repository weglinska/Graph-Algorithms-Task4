#ifndef MAXSTRONGLYCONNECTEDCOMPONENT_H
#define MAXSTRONGLYCONNECTEDCOMPONENT_H
#include "directedgraph.h"

/**
 * @brief The MaxStronglyConnectedComponent class
 * Klasa realizuje zadanie nr 2 z zestawu IV
 */
class MaxStronglyConnectedComponent
{
private:
    MaxStronglyConnectedComponent();
public:
    // metoda znajduje najwieksza silnie spojna skladowa
    // tworzy z niej nowy digraf i zwraca go
    static DirectedGraph* getMaxStronglyConnectedComponent(DirectedGraph* diGraphTmp);

    // metoda sprawdza, czy digraf zawiera cykl ujemny
    static bool hasNegativeCycle(DirectedGraph* diGraph);

    // efektem metody jest wypelnienie tablicy distance odleglosciami
    // uwaga: ta metoda numeruje wszystkie wierzcholki od 0
    // uzywany jest algorytm Bellmana-Forda
    // zwraca true jezeli graf nie zawiera cykli ujemnych, w przeciwnym wypadku false
    // zwraca takze false, jezeli digraf ma 0 wierzcholkow
    static bool getDistances(DirectedGraph* diGraph, unsigned int sVertex, std::vector<int>& distances);
};

#endif // MAXSTRONGLYCONNECTEDCOMPONENT_H
