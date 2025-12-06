#include <iostream>
#include <vector>
using namespace std;

// Detect cycle in a directed graph using DFS

bool dfs(int u, const vector<vector<int>>& adj, vector<int>& state) {
    // state: 0 = unvisited, 1 = visiting, 2 = visited
    state[u] = 1; // visiting
    for (int v : adj[u]) {
        if (state[v] == 0) {
            if (!dfs(v, adj, state)) return false;
        } else if (state[v] == 1) {
            // back edge to a node in current recursion stack => cycle
            return false;
        }
    }
    state[u] = 2; // done
    return true;
}

bool hasNoCycle(int n, const vector<vector<int>>& adj) {
    vector<int> state(n, 0);
    for (int i = 0; i < n; ++i) {
        if (state[i] == 0) {
            if (!dfs(i, adj, state)) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Cycle Detection in Directed Graph (DFS)\n";
    cout << "Enter number of vertices and edges: ";
    int n, m;
    if (!(cin >> n >> m) || n <= 0 || m < 0) return 0;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " directed edges (u v) with 0-based indices:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge indices.\n";
            return 0;
        }
        adj[u].push_back(v);
    }

    if (hasNoCycle(n, adj)) cout << "The directed graph has NO cycle.\n";
    else cout << "The directed graph HAS a cycle.\n";

    return 0;
}