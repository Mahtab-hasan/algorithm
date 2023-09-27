#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1000;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
char a[N][N];
bool vis[N][N];
bool IsValid(int ci, int cj)
{
    return ci >= 0 && ci < n && cj >= 0 && cj < m && a[ci][cj] == '.';
}
int bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int cmp = 0;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        cmp++;
        for (const auto &m : path)
        {
            int cI = pI + m.first;
            int cJ = pJ + m.second;
            if (IsValid(cI, cJ) && !vis[cI][cJ])
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
            }
        }
    }
    return cmp;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int area = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && a[i][j] == '.')
            {
                int cmp = bfs(i, j);
                if (cmp < area)
                {
                    area = cmp;
                }
            }
        }
    }
    if (area == INT_MAX)
    {

        cout << -1 << endl;
    }
    else
    {

        cout << area << endl;
    }

    return 0;
}