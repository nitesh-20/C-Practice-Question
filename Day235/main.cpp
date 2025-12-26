#include <iostream>
#include <vector>
#include <limits>

// Floyd–Warshall Algorithm
// Computes all-pairs shortest paths in O(V^3).
// Works with negative edges (no negative cycles for meaningful distances).

int main() {
    std::cout << "===== Floyd–Warshall All-Pairs Shortest Path Demo =====\n";

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of directed edges: ";
    std::cin >> m;

    if (n <= 0 || m < 0) {
        std::cout << "Invalid input. Exiting.\n";
        return 0;
    }

    const long long INF = std::numeric_limits<long long>::max() / 4; // avoid overflow

    // dist[i][j] = shortest known distance from i to j
    std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));

    for (int i = 0; i < n; ++i) dist[i][i] = 0; // distance to self is 0

    std::cout << "Enter edges in the form: u v w (directed edge u -> v with weight w, can be negative)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            std::cout << "Invalid edge, skipping.\n";
            continue;
        }
        if (w < dist[u][v]) { // keep the smallest weight for multiple edges
            dist[u][v] = w;
        }
    }

    // Floyd–Warshall core
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue;
                long long throughK = dist[i][k] + dist[k][j];
                if (throughK < dist[i][j]) {
                    dist[i][j] = throughK;
                }
            }
        }
    }

    // Detect negative cycles: if dist[i][i] < 0 for any i, there's a negative cycle reachable from i
    bool hasNegativeCycle = false;
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        std::cout << "Graph contains a negative-weight cycle. Some shortest paths are not well-defined.\n";
    }

    std::cout << "All-pairs shortest path distance matrix (INF = no path):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << dist[i][j];
            }
            if (j + 1 < n) std::cout << '\t';
        }
        std::cout << '\n';
    }

    return 0;
}
