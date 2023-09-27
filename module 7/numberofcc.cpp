#include <bits/stdc++.h>
using namespace std;
const int n = 1e3 + 5;
vector<int> adj[n];
bool visited[n];
// int level[n];
void dfs(int u)
{
    for (int v : adj[u])
    {
        visited[u] = true;
        if (visited[v])
            continue;
        dfs(v);
    }
}
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         cout << " Visited Node : " << u << endl;
//         for (int v : adj[u])
//         {
//             if (visited[v] == true)
//                 continue;
//             q.push(v);
//             visited[v] = true;
//             level[v] = level[u] + 1;
//         }
//     }
// }
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
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cc++;
    }
    cout << "Number of c c:" << cc << endl;

    return 0;
}