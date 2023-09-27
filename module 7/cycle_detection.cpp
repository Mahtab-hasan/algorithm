#include <bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5;
vector<int> adj[n];
bool visited[n];

bool dfs(int u, int p = -1)
{
    bool cycleExist = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        cycleExist = cycleExist | dfs(v, u);
    }
    return cycleExist;
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
    bool iscyle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        iscyle |= dfs(i);
    }
    if (iscyle)
        cout << "Cycle deteceted!\n";
    else
        cout << "No cycle!\n";
    return 0;
}