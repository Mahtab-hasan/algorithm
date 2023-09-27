#include <bits/stdc++.h>
#define pi pair<int, long long>
using namespace std;
vector<vector<pi>> adj;
vector<bool> vis;
long long prim(int s)
{
    int n = adj.size();
    vis.assign(n, false);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    long long mincost = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int parent = pq.top().second;
        long long dis = pq.top().first;
        pq.pop();
        if (vis[parent])
            continue;
        vis[parent] = true;
        mincost += dis;
        for (const pi &child : adj[parent])
        {
            int childnode = child.first;
            long long childcost = child.second;
            if (!vis[childnode])
            {
                pq.push({childcost, childnode});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            return -1;
    }
    return mincost;
}
int main()
{
    int n, e;
    cin >> n >> e;
    adj.resize(n);
    vis.resize(n, false);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    long long mincost = prim(0);
    if (mincost == -1)
        cout << "-1" << endl;
    else
        cout << mincost << endl;

    return 0;
}