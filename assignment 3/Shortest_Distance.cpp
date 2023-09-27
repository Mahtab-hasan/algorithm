#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<long long>> adj(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        if (adj[a][b] > w)
        {
            adj[a][b] = w;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] != INF && adj[k][j] != INF)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, d;
        cin >> s >> d;
        if (adj[s][d] == INF)
            cout << "-1" << endl;
        else
            cout << adj[s][d] << endl;
    }

    return 0;
}