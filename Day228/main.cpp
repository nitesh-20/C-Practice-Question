#include <iostream>
#include <vector>
#include <limits>
#include <queue>

// Shortest path in a Directed Acyclic Graph (DAG)
// Approach:
// 1. Topological sort using DFS or Kahn's algorithm.
// 2. Relax edges in topological order (similar to DP on DAG).
// Time: O(V + E)

struct Edge {
    int to;
    int weight;
};

void topologicalSortUtil(int v, const std::vector<std::vector<Edge>> &adj,
                         std::vector<bool> &visited, std::vector<int> &order) {
    visited[v] = true;
    for (const auto &e : adj[v]) {
        if (!visited[e.to]) {
            topologicalSortUtil(e.to, adj, visited, order);
        }
    }
    order.push_back(v); // post-order
}

std::vector<int> shortestPathDAG(int n, const std::vector<std::vector<Edge>> &adj, int src) {
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist(n, INF);

    // 1. Topological sort
    std::vector<bool> visited(n, false);
    std::vector<int> order;
    order.reserve(n);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, order);
        }
    }

    // order now has vertices in reverse topological order
    std::reverse(order.begin(), order.end());

    // 2. Initialize source
    dist[src] = 0;

    // 3. Relax edges in topological order
    for (int u : order) {
        if (dist[u] == INF) continue; // unreachable
        for (const auto &e : adj[u]) {
            if (dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
            }
        }
    }

    return dist;
}

int main() {
    std::cout << "===== Shortest Path in DAG Demo =====\n";

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of directed edges: ";
    std::cin >> m;

    if (n <= 0 || m < 0) {
        std::cout << "Invalid input. Exiting.\n";
        return 0;
    }

    std::vector<std::vector<Edge>> adj(n);

    std::cout << "Enter edges in the form: u v w (edge u -> v with weight w)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            std::cout << "Invalid edge, skipping.\n";
            continue;
        }
        adj[u].push_back({v, w});
    }

    int src;
    std::cout << "Enter source vertex: ";
    std::cin >> src;

    if (src < 0 || src >= n) {
        std::cout << "Invalid source. Exiting.\n";
        return 0;
    }

    std::vector<int> dist = shortestPathDAG(n, adj, src);

    const int INF = std::numeric_limits<int>::max();
    std::cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Vertex " << i << ": ";
        if (dist[i] == INF) {
            std::cout << "INF (unreachable)\n";
        } else {
            std::cout << dist[i] << "\n";
        }
    }

    return 0;
}
