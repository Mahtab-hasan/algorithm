#include <bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5;
int adjmat[n][n];
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjmat[u][v] = w; // undirected
        adjmat[v][u] = w; // directed
        // int u, v;
        // cin >> u >> v;
        // adjmat[u][v] = 1; // undirected
        // adjmat[v][u] = 1; // directed
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}