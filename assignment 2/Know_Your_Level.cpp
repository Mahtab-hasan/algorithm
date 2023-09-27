// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector<vector<int>> adjlist(n);
//     for (int i = 0; i < e; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         adjlist[a].push_back(b);
//         adjlist[b].push_back(a);
//     }
//     int l;
//     cin >> l;
//     vector<int> level(n, -1);
//     level[0] = 0;
//     queue<int> q;
//     q.push(0);
//     while (!q.empty())
//     {
//         int curr = q.front();
//         q.pop();
//         for (int v : adjlist[curr])
//         {
//             if (level[v] == -1)
//             {
//                 level[v] = level[curr] + 1;
//                 q.push(v);
//             }
//         }
//     }
//     set<int> pizza;
//     for (int i = 0; i < n; i++)
//     {
//         if (level[i] == l)
//         {
//             pizza.insert(i);
//         }
//     }
//     if (pizza.empty())
//     {
//         cout << "-1" << endl;
//     }
//     else
//     {
//         for (int shop : pizza)
//         {
//             cout << shop << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
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
        adjlist[b].push_back(a);
    }
    int l;
    cin >> l;
    vector<bool> visited(n, false);
    set<int> pizza;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int currshop = q.front().first;
        int curr = q.front().second;
        q.pop();
        if (visited[currshop])
            continue;
        visited[currshop] = true;
        if (curr == l)
        {
            pizza.insert(currshop);
        }
        for (int v : adjlist[currshop])
        {
            q.push({v, curr + 1});
        }
    }
    if (pizza.empty())
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int shop : pizza)
        {
            cout << shop << " ";
        }
        cout << endl;
    }

    return 0;
}
