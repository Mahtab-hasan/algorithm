#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const long long INF = 1e18 + 7;

class Edge
{
public:
    int u;
    int v;
    int w;

    Edge() : u(0), v(0), w(0) {} // Default constructor

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool bellmanFord(int N, int E, int S, vector<Edge> &edges, vector<long long> &dist)
{
    dist.assign(N + 1, INF);
    dist[S] = 0;

    for (int i = 1; i <= N - 1; i++)
    {
        for (const Edge &child : edges)
        {

            if (dist[a] != INF && dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge &child : edges)
    {
        int a = child.u;
        int b = child.v;
        int w = child.w;

        if (dist[a] != INF && dist[a] + w < dist[b])
        {
            return false; // Negative weight cycle detected
        }
    }

    return true;
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int S;
    cin >> S;

    int T;
    cin >> T;

    vector<long long> dist(N + 1);

    if (bellmanFord(N, E, S, edges, dist))
    {
        while (T--)
        {
            int D;
            cin >> D;

            if (dist[D] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dist[D] << endl;
            }
        }
    }
    else
    {
        cout << "Negative Cycle Detected" << endl;
    }

    return 0;
}
