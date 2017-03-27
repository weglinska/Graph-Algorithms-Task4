#include "shortestpaths.h"
#define INF 999999

ShortestPaths::ShortestPaths()
{

}




void ShortestPaths::floydWarshall(DirectedGraph* graph)
{
    int size=graph->getVerticesNumber();

    int **matrix=graph->getDistanceMatrix();
    bool **adjacency=graph->getAdjacencyMatrix();
    int **weights=graph->getWeightMatrix();


    // nie ma oszukiwania
    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
            matrix[i][j]=0;

    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            matrix[i][j]=INF;
        }
        matrix[i][i]=0;

        for (int j=0; j<size; ++j)
        {
            if (adjacency[i][j])
            {
                matrix[i][j]=weights[i][j];
            }
        }
    }

    for (int k=0; k<size; ++k)
        for (int i=0; i<size; ++i)
            for (int j=0; j<size; ++j)
                if (matrix[i][k]!=INF && matrix[k][j]!=INF)
                    if (matrix[i][j]>matrix[i][k]+matrix[k][j])
                        matrix[i][j]=matrix[i][k]+matrix[k][j];

}

int ShortestPaths::bellmanFord(DirectedGraph* graph, int w, int s)
{
    int size=graph->getVerticesNumber();
    int **weights=graph->getWeightMatrix();
    bool **adjacency=graph->getAdjacencyMatrix();

    if (s<size)
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

        return d[w];
    }

}

void ShortestPaths::dijkstry(DirectedGraph* graph, int source)
{


    int size=graph->getVerticesNumber();
    bool **adjacency=graph->getAdjacencyMatrix();
    if (source<size)
    {
        int d[size];
        int prev[size];
        std::vector<int> queue;
        for (int i=0; i<size; ++i)
        {
            d[i]=INF;
            prev[i]=size;
            queue.push_back(i);
        }

        d[source]=0;
        prev[source]=source;

        while(queue.size())
        {
            //zdejmowanie minimum z kolejki
            int u=queue[0];
            int index=0;
            for (unsigned int i=1; i<queue.size(); ++i)
            {
                if (d[queue[i]]<d[u])
                {
                    u=queue[i];
                    index=i;
                }
            }
            queue.erase(queue.begin()+index);
            for (unsigned int i=0; i<queue.size(); ++i)
            {
                int waga=graph->getWeight(u, queue[i]);
                if (adjacency[u][queue[i]])
                {
                    if (d[queue[i]]>d[u]+waga)
                    {
                        d[queue[i]]=d[u]+waga;
                        prev[queue[i]]=u;
                    }
                }
            }
        }
        int **matrix=graph->getDistanceMatrix();
        for (int i=0; i<size; ++i)
        {
            matrix[source][i]=d[i];

        }
    }
}

void ShortestPaths::johnson(DirectedGraph* graph)
{

    int size=graph->getVerticesNumber();
    int **distances=graph->getDistanceMatrix();
    // nie ma oszukiwania
    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
            distances[i][j]=0;
    bool **adjacency=graph->getAdjacencyMatrix();
    int **weights=graph->getWeightMatrix();

    // stworzenie Gragu G z dodanym wierzcholkiem S
    bool **adjacency_copy=new bool* [size+1];
    for(int i=0; i<size+1; i++)
        adjacency_copy[i]=new bool[size+1];

    for (int i=0; i<size+1; ++i)
    {
        adjacency_copy[size][i]=true;
        adjacency_copy[i][size]=false;

    }

    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
        {
            adjacency_copy[i][j]=adjacency[i][j];
        }


    DirectedGraph *G=new DirectedGraph(adjacency_copy, size+1);


    int **distance_copy=G->getDistanceMatrix();
    int **weight_copy=G->getWeightMatrix();

    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
        {
            weight_copy[i][j]=weights[i][j];
        }


    for (int i=0; i<size+1; ++i)
    {
        weight_copy[i][size]=0;
        weight_copy[size][i]=0;
    }


    // wartości wierzcholkow
    int h[size+1];

    for (int i=0; i<size+1; ++i)
    {
        h[i]=bellmanFord(G, size, i);
    }


    // obliczenie nowych wag krawedzi
    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
        {
            if (adjacency[i][j])
                weights[i][j]=weights[i][j]+h[i]-h[j];

        }

    for (int k=0; k<size; ++k)
    {
        dijkstry(graph, k);
    }

    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
            if (distances[i][j]!=INF && i!=j)
                    distances[i][j]+=h[j]-h[i];

    for (int i=0; i<size; ++i)
        for (int j=0; j<size; ++j)
        {
            if (adjacency[i][j])
                weights[i][j]=weights[i][j]-h[i]+h[j];

        }
}

