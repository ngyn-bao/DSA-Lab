#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> graph, int start)
{
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int x : graph[current])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}