#include <bits/stdc++.h>
using namespace std;
const int n = 1e3 + 5;
vector<int> adj[n];
bool visited[n];
int level[n];
int parent[n];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // cout << " Visited Node : " << u << endl;
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
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
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout << "distance: " << level[d] << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "parent of " << i << ": " << parent[i] << endl;
    // }
    vector<int> path;
    int curr = d;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    cout << "path : ";
    for (int node : path)
    {
        cout << node << " ";
    }
    return 0;
}