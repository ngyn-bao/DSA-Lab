#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
    list<int> adjList;
    int size;

public:
    Adjacency() {}
    Adjacency(int V) {}
    void push(int data)
    {
        adjList.push_back(data);
        size++;
    }
    void print()
    {
        for (auto const &i : adjList)
            cout << " -> " << i;
    }
    void printArray()
    {
        for (auto const &i : adjList)
            cout << i << " ";
    }
    int getSize() { return adjList.size(); }
    int getElement(int idx)
    {
        auto it = adjList.begin();
        advance(it, idx);
        return *it;
    }
};

class Graph
{

    int V;
    Adjacency *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push(w);
    }

    // Heling functions
    void topologicalSortUtil(int v, list<bool> &visited, list<int> &sorted)
    {
        auto visitedIt = visited.begin();
        advance(visitedIt, v);
        *visitedIt = true;

        for (int i = 0; i < adj[v].getSize(); i++)
        {
            int x = adj[v].getElement(i);
            visitedIt = visited.begin();
            advance(visitedIt, x);
            if (!*visitedIt)
                topologicalSortUtil(x, visited, sorted);
        }

        sorted.push_front(v);
    }

    void topologicalSort()
    {
        list<bool> visited(V, false);
        list<int> sorted;

        for (int i = 0; i < V; i++)
        {
            auto visitedIt = visited.begin();
            advance(visitedIt, i);

            if (!*visitedIt)
                topologicalSortUtil(i, visited, sorted);
        }

        for (int v : sorted)
            cout << v << " ";
        cout << endl;
    }
};