#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjlist(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int k;
    cin >> k;
    int direct = adjlist[k].size();
    cout << direct << endl;
    return 0;
}