#include <iostream>
#include <vector>
#include <algorithm>

// Articulation Points (Cut Vertices) in an Undirected Graph
// Uses DFS (Tarjan's algorithm).
// Time complexity: O(V + E).

void dfsAP(int u, int parent, std::vector<std::vector<int>> &adj,
           std::vector<int> &disc, std::vector<int> &low,
           std::vector<bool> &vis, std::vector<bool> &isAP, int &timer) {
    vis[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;
        if (!vis[v]) {
            ++children;
            dfsAP(v, u, adj, disc, low, vis, isAP, timer);
            low[u] = std::min(low[u], low[v]);

            // If u is not root and low[v] >= disc[u], u is an articulation point
            if (parent != -1 && low[v] >= disc[u]) {
                isAP[u] = true;
            }
        } else {
            // Back edge
            low[u] = std::min(low[u], disc[v]);
        }
    }

    // Root is articulation point if it has more than one child
    if (parent == -1 && children > 1) {
        isAP[u] = true;
    }
}

int main() {
    std::cout << "===== Articulation Points (Cut Vertices) Demo =====\n";

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
    std::vector<bool> vis(n, false), isAP(n, false);
    int timer = 0;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfsAP(i, -1, adj, disc, low, vis, isAP, timer);
        }
    }

    std::cout << "Articulation points in the graph: ";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (isAP[i]) {
            std::cout << i << ' ';
            found = true;
        }
    }
    if (!found) {
        std::cout << "(none)";
    }
    std::cout << '\n';

    return 0;
}
