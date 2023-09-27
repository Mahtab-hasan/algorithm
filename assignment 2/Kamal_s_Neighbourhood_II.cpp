#include <bits/stdc++.h>
using namespace std;
void dfs(int n, const vector<vector<int>> &adjlist, vector<bool> &visited)
{
    visited[n] = true;
    for (int v : adjlist[n])
    {
        if (!visited[v])
        {
            dfs(v, adjlist, visited);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjlist(n);

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
    }
    int k;
    cin >> k;
    vector<bool> visited(n, false);
    dfs(k, adjlist, visited);
    int count = 0;
    for (bool num : visited)
    {
        if (num)
        {
            count++;
        }
    }
    cout << count -1<< endl;
    return 0;
}