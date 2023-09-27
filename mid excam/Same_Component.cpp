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
bool bfs(int si, int sj, int sR, int sC)
{
    queue<pi> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        if (pI == sR && pJ == sC)
        {
            return true;
        }
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
    return false;
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
    int si, sj, sR, sC;
    cin >> si >> sj >> sR >> sC;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }
    if (bfs(si, sj, sR, sC))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}