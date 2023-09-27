#include <bits/stdc++.h>
#define pi pair<int, long long>
using namespace std;
const long long INF = 1e18;

int main()
{
    int N, E;
    cin >> N >> E;

    vector<vector<pi>> adj(N + 1); // Adjacency list
    for (int i = 0; i < E; ++i)
    {
        int A, B;
        long long W;
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
    }

    int S;
    cin >> S;

    int T;
    cin >> T;
    while (T--)
    {
        int D;
        long long DW;
        cin >> D >> DW;

        vector<long long> dis(N + 1, INF);
        dis[S] = 0;

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, S});

        while (!pq.empty())
        {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dis[u])
            {
                continue;
            }

            for (const auto &edge : adj[u])
            {
                int v = edge.first;
                long long w = edge.second;

                if (dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        if (dis[D] <= DW)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
