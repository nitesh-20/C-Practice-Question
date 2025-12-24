#include <iostream>
#include <vector>
#include <limits>

// Bellman-Ford algorithm
// Handles graphs with negative edge weights and detects negative cycles reachable from source.

struct Edge {
    int u;
    int v;
    int w;
};

int main() {
    std::cout << "===== Bellman-Ford Shortest Path Demo =====\n";

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of directed edges: ";
    std::cin >> m;

    if (n <= 0 || m < 0) {
        std::cout << "Invalid input. Exiting.\n";
        return 0;
    }

    std::vector<Edge> edges;
    edges.reserve(m);

    std::cout << "Enter edges in the form: u v w (directed edge u -> v with weight w, can be negative)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            std::cout << "Invalid edge, skipping.\n";
            continue;
        }
        edges.push_back({u, v, w});
    }

    int src;
    std::cout << "Enter source vertex: ";
    std::cin >> src;

    if (src < 0 || src >= n) {
        std::cout << "Invalid source. Exiting.\n";
        return 0;
    }

    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist(n, INF);
    dist[src] = 0;

    // Relax edges (n - 1) times
    for (int i = 0; i < n - 1; ++i) {
        bool changed = false;
        for (const auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break; // optimization: stop early if no update
    }

    // Check for negative-weight cycles reachable from src
    bool hasNegativeCycle = false;
    for (const auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        std::cout << "Graph contains a negative-weight cycle reachable from the source.\n";
        std::cout << "Shortest paths are not well-defined.\n";
    } else {
        std::cout << "Shortest distances from source " << src << ":\n";
        for (int v = 0; v < n; ++v) {
            std::cout << "Vertex " << v << ": ";
            if (dist[v] == INF) {
                std::cout << "INF (unreachable)\n";
            } else {
                std::cout << dist[v] << "\n";
            }
        }
    }

    return 0;
}
