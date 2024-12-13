int numberOfFriendGroups(vector<vector<int>> &friends)
{
    int n = friends.size();        
    vector<bool> visited(n, false);
    int friendGroups = 0;          

    // Helper function for DFS traversal
    auto dfs = [&](int node, auto &dfsRef) -> void
    {
        visited[node] = true;
        for (int neighbor : friends[node])
        {
            if (!visited[neighbor])
            {
                dfsRef(neighbor, dfsRef); 
            }
        }
    };

    // Iterate through all nodes
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        { 
            ++friendGroups;
            dfs(i, dfs);
        }
    }

    return friendGroups;
}