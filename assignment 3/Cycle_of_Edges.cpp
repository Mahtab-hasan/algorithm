#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
void dfs(int N, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &parent, int &cnt)
{
    vis[N] = true;
    for (int node : adj[N])
    {
        if (!vis[node])
        {
            parent[node] = N;
            dfs(node, adj, vis, parent, cnt);
        }
        else if (node != parent[N])
            cnt++;
    }
}
int find(int node, vector<pi> &edge)
{
    vector<vector<int>> adj(node);
    vector<bool> vis(node, false);
    vector<int> parent(node, -1);
    int cnt = 0;
    for (const auto &ed : edge)
    {
        int a = ed.first - 1;
        int b = ed.second - 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, adj, vis, parent, cnt);
    return cnt / 2;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pi> edge;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
    }
    int result = find(n, edge);
    cout << result << endl;

    return 0;
}