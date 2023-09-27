#include <bits/stdc++.h>
using namespace std;
const int n = 100005;
vector<int> adj[n];
int level[n];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    for (int i = 0; i < n; i++)
    {
        level[i] = -1;
    }
    level[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (level[v] == -1)
            {
                q.push(v);
                level[v] = level[u] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        bfs(0);
        if (level[d] == -1)
            cout << -1 << endl;
        else
            cout << level[d] << endl;
    }
    return 0;
}