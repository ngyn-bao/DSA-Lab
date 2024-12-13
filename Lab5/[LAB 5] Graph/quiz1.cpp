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

    Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        list<int> q;

        list<bool> visited(V, false);

        auto visitedIt = visited.begin();
        advance(visitedIt, v);
        *visitedIt = true;

        Adjacency *result = new Adjacency();

        q.push_back(v);

        while (!q.empty())
        {
            int current = q.front();
            q.pop_front();
            result->push(current);

            for (int i = 0; i < this->adj[current].getSize(); i++)
            {
                int x = this->adj[current].getElement(i);
                visitedIt = visited.begin();
                advance(visitedIt, x);
                if (!*visitedIt)
                {
                    *visitedIt = true;
                    q.push_back(x);
                }
            }
        }
        return result;
    }
};