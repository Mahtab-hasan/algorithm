#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const long long INF = 1e18;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pi>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    int s;
    cin >> s;
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        long long dw;
        cin >> d >> dw;
        vector<long long> dis(n + 1, INF);
        dis[s] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, s});
        while (!pq.empty())
        {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dis[u])
                continue;
            for (const auto &m : adj[u])
            {
                int v = m.first;
                long long w = m.second;
                if (dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        if (dis[d] <= dw)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}