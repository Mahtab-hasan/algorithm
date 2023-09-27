// #include <bits/stdc++.h>
// using namespace std;
// void dfs(int n, const vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &cs)
// {
//     visited[n] = true;
//     cs.push_back(n);
//     for (int v : adjlist[n])
//     {
//         if (!visited[v])
//         {
//             dfs(v, adjlist, visited, cs);
//         }
//     }
// }
// vector<vector<int>> find_c(vector<vector<int>> &adjlist, int n)
// {
//     vector<bool> visited(n+1,false);
//     vector<vector<int>> cs;
//     for (int i = ; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             vector<int> c;
//             dfs(i, adjlist, visited, c);
//             cs.push_back(c);
//         }
//     }
//     return cs;
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector<vector<int>> adjlist(n + 1);

//     for (int i = 0; i < e; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         adjlist[a].push_back(b);
//         adjlist[b].push_back(a);
//     }
//     vector<vector<int>> cs = find_c(adjlist, n + 1);
//     sort(cs.begin(), cs.end(), [](const vector<int> &a, const vector<int> &b)
//          { return a.size() < b.size(); });
//     for (const vector<int> &c : cs)
//     {
//         if (c.size() > 1)
//         {
//             cout << c.size() << " ";
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void dfs(int n, const vector<vector<int>> &adjlist, vector<bool> &visited, vector<int> &cs)
{
    visited[n] = true;
    cs.push_back(n);
    for (int v : adjlist[n])
    {
        if (!visited[v])
        {
            dfs(v, adjlist, visited, cs);
        }
    }
}

vector<vector<int>> find_c(vector<vector<int>> &adjlist, int n)
{
    vector<bool> visited(n + 1, false);
    vector<vector<int>> cs;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<int> c;
            dfs(i, adjlist, visited, c);
            cs.push_back(c);
        }
    }
    return cs;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjlist(n + 1);

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    vector<vector<int>> cs = find_c(adjlist, n);

    for (const vector<int> &c : cs)
    {
        for (int node : c)
        {
            cout << node << " "; // Debugging output
        }
        cout << endl; // Debugging output

        if (c.size() > 1)
        {
            cout << c.size() << " ";
        }
    }

    return 0;
}
