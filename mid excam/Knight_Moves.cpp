#include <bits/stdc++.h>
using namespace std;
const int dirx[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int diry[] = {1, -1, 2, -2, 2, -2, 1, -1};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ki, kj;
        cin >> ki >> kj;
        int qi, qj;
        cin >> qi >> qj;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        dist[ki][kj] = 0;
        queue<pair<int, int>> q;
        q.push({ki, kj});
        while (!q.empty())
        {
            int pi = q.front().first;
            int pj = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int ci = pi + dirx[i];
                int cj = pj + diry[i];
                if (ci >= 0 && ci < n && cj >= 0 && cj < m && dist[ci][cj] == -1)
                {
                    dist[ci][cj] = dist[pi][pj] + 1;
                    q.push({ci, cj});
                }
            }
        }
        if (dist[qi][qj] != -1)
            cout << dist[qi][qj] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}