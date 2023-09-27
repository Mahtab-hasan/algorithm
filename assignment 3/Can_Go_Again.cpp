#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
class Edge
{
public:
    int u;
    int v;
    int w;
    Edge() : u(0), v(0), w(0) {}
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool bellman(int n, int e, int s, vector<Edge> &edges, vector<long long> &dis)
{
    dis.assign(n + 1, INF);
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (const Edge &child : edges)
        {
            int a = child.u;
            int b = child.v;
            int w = child.w;
            if (dis[a] != INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    for (const Edge &child : edges)
    {
        int a = child.u;
        int b = child.v;
        int w = child.w;
        if (dis[a] != INF && dis[a] + w < dis[b])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int s;
    cin >> s;
    int t;
    cin >> t;
    vector<long long> dis(n + 1);
    if (bellman(n, e, s, edges, dis))
    {
        while (t--)
        {
            int d;
            cin >> d;
            if (dis[d] == INF)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
    else
        cout << "Negative Cycle Detected" << endl;

    return 0;
}