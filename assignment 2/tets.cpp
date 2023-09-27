// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void dfs(int node, const vector<vector<int>> &graph, vector<bool> &visited, int &componentSize)
// {
//     visited[node] = true;
//     componentSize++;

//     for (int neighbor : graph[node])
//     {
//         if (!visited[neighbor])
//         {
//             dfs(neighbor, graph, visited, componentSize);
//         }
//     }
// }

// int main()
// {
//     int N, E;
//     cin >> N >> E;

//     vector<vector<int>> graph(N); // Adjacency list representation of the graph
//     for (int i = 0; i < E; ++i)
//     {
//         int A, B;
//         cin >> A >> B;
//         graph[A].push_back(B);
//         graph[B].push_back(A); // Since the graph is undirected
//     }

//     vector<bool> visited(N, false);
//     vector<int> componentSizes;

//     for (int i = 0; i < N; ++i)
//     {
//         if (!visited[i])
//         {
//             int cs = 0;
//             dfs(i, graph, visited, cs);
//             if (cs > 1)
//             { // Exclude single node components
//                 componentSizes.push_back(cs);
//             }
//         }
//     }

//     sort(componentSizes.begin(), componentSizes.end());

//     for (int size : componentSizes)
//     {
//         cout << size << " ";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, visited, component);
        }
    }
}

vector<vector<int>> find_components(vector<vector<int>> &graph, int n)
{
    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, graph, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n + 1); // Adjusted for 1-based node numbers
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> components = find_components(graph, n + 1); // Adjusted for 1-based node numbers

    sort(components.begin(), components.end(), [](const vector<int> &a, const vector<int> &b)
         { return a.size() < b.size(); });

    for (const vector<int> &component : components)
    {
        if (component.size() > 1)
        {
            cout << component.size() << " ";
        }
    }

    return 0;
}
