#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

// Medium level DSA: Shortest path in a weighted Directed Acyclic Graph (DAG)
// Uses topological sort + DP-style relaxation.

struct Edge {
    int to;
    int w;
};

void dfsTopo(int u, const vector<vector<Edge>> &adj, vector<bool> &vis, vector<int> &order) {
    vis[u] = true;
    for (const auto &e : adj[u]) {
        if (!vis[e.to]) dfsTopo(e.to, adj, vis, order);
    }
    order.push_back(u); // post-order
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== Shortest Path in Weighted DAG (Topo + DP) =====\n";

    int n, m;
    cout << "Enter number of vertices: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n. Exiting.\n";
        return 0;
    }

    cout << "Enter number of directed edges: ";
    cin >> m;
    if (m < 0) {
        cout << "Invalid m. Exiting.\n";
        return 0;
    }

    vector<vector<Edge>> adj(n);
    cout << "Enter edges as: u v w  (directed edge u -> v with weight w, can be positive/zero)\n";
    cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge, skipping.\n";
            continue;
        }
        adj[u].push_back({v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    if (src < 0 || src >= n) {
        cout << "Invalid source. Exiting.\n";
        return 0;
    }

    const int INF = numeric_limits<int>::max();
    vector<int> dist(n, INF);

    // Topological order via DFS
    vector<bool> vis(n, false);
    vector<int> order;
    order.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfsTopo(i, adj, vis, order);
    }
    reverse(order.begin(), order.end());

    dist[src] = 0;

    for (int u : order) {
        if (dist[u] == INF) continue; // unreachable
        for (const auto &e : adj[u]) {
            if (dist[u] + e.w < dist[e.to]) {
                dist[e.to] = dist[u] + e.w;
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INF) cout << "INF (unreachable)\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
