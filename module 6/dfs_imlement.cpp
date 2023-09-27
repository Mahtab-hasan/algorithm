#include <bits/stdc++.h>
using namespace std;
const int n = 1e3 + 5;
vector<int> adj[n];
bool visited[n];
void dfs(int u)
{
    visited[u] = true;
    cout << "Visiting Node: " << u << endl;
    for (int v : adj[u])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << ": ";
    //     for (int j : adj[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    dfs(1);

    return 0;
}