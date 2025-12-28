#include <iostream>
#include <vector>
#include <algorithm>

// Bridges (Critical Edges) in an Undirected Graph
// Uses DFS (Tarjan's algorithm for bridges).
// Time complexity: O(V + E).

void dfsBridges(int u, int parent, std::vector<std::vector<int>> &adj,
                std::vector<int> &disc, std::vector<int> &low,
                std::vector<bool> &vis, int &timer,
                std::vector<std::pair<int, int>> &bridges) {
    vis[u] = true;
    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (!vis[v]) {
            dfsBridges(v, u, adj, disc, low, vis, timer, bridges);
            low[u] = std::min(low[u], low[v]);

            // If low[v] > disc[u], then edge (u, v) is a bridge
            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else {
            // Back edge
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

int main() {
    std::cout << "===== Bridges (Critical Edges) Demo =====\n";

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of undirected edges: ";
    std::cin >> m;

    if (n <= 0 || m < 0) {
        std::cout << "Invalid input. Exiting.\n";
        return 0;
    }

    std::vector<std::vector<int>> adj(n);

    std::cout << "Enter edges in the form: u v (undirected edge between u and v)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            std::cout << "Invalid edge, skipping.\n";
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> disc(n, 0), low(n, 0);
    std::vector<bool> vis(n, false);
    std::vector<std::pair<int, int>> bridges;
    int timer = 0;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfsBridges(i, -1, adj, disc, low, vis, timer, bridges);
        }
    }

    std::cout << "Bridges (critical edges) in the graph: ";
    if (bridges.empty()) {
        std::cout << "(none)";
    } else {
        for (auto &e : bridges) {
            std::cout << "(" << e.first << ", " << e.second << ") ";
        }
    }
    std::cout << '\n';

    return 0;
}
