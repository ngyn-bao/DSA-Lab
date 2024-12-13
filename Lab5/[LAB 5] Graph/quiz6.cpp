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
private:
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
        adj[w].push(v);
    }

    void printGraph()
    {
        for (int v = 0; v < V; ++v)
        {
            cout << "\nAdjacency list of vertex " << v << "\nhead ";
            adj[v].print();
        }
    }

    void DFSHelper(int v, list<bool> &visited, Adjacency *result)
    {
        auto visitedIt = visited.begin();
        advance(visitedIt, v);
        *visitedIt = true;

        result->push(v);

        for (int i = 0; i < this->adj[v].getSize(); i++)
        {
            int x = this->adj[v].getElement(i);
            visitedIt = visited.begin();
            advance(visitedIt, x);

            if (!*visitedIt)
            {
                DFSHelper(x, visited, result);
            }
        }
    }

    Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        list<bool> visited(V, false);
        Adjacency *result = new Adjacency();

        DFSHelper(v, visited, result);
        return result;
    }
};