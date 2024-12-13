#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
// Some helping functions
#define V 6

int Dijkstra(int **graph, int src, int dst)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    vector<bool> processed(V, false);

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        if (u == dst)
        {
            return dist[dst];
        }

        for (int v = 0; v < V; v++)
        {

            if (graph[u][v] != 0 && !processed[v])
            {
                // Relax the edge (u, v)
                if (dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push({dist[v], v});
                }
            }
        }
    }

    return -1;
}
