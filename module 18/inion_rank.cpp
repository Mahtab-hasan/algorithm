#include <iostream>
#include <vector>

using namespace std;

// Function to perform Depth-First Search (DFS)
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent, int& cycle_edges_count) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            dfs(neighbor, adj, visited, parent, cycle_edges_count);
        } else if (neighbor != parent[node]) {
            // If the neighbor is visited but not the parent, it's part of a cycle.
            cycle_edges_count++;
        }
    }
}

// Function to find the number of edges that can create a cycle
int findCycleEdges(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    int cycle_edges_count = 0;

    // Build the adjacency list representation of the graph
    for (const auto& edge : edges) {
        int a = edge.first - 1;
        int b = edge.second - 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Start DFS from an arbitrary node (e.g., node 0)
    dfs(0, adj, visited, parent, cycle_edges_count);

    // The number of edges that can create a cycle is half of cycle_edges_count
    return cycle_edges_count / 2;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edges;

    // Input edge data
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    int result = findCycleEdges(n, edges);
    cout << result << endl;

    return 0;
}
