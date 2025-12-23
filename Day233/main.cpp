#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

// Dijkstra's algorithm with path reconstruction
// Finds shortest paths from a single source in a graph with non-negative edge weights.

struct Edge {
    int to;
    int weight;
};

struct Node {
    int vertex;
    int dist;
    bool operator>(const Node &other) const {
        return dist > other.dist;
    }
};

void dijkstraWithPath(int n, const std::vector<std::vector<Edge>> &adj, int src,
                      std::vector<int> &dist, std::vector<int> &parent) {
    const int INF = std::numeric_limits<int>::max();
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[src] = 0;

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({src, 0});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;

        if (node.dist != dist[u]) continue; // outdated entry

        for (const auto &e : adj[u]) {
            if (dist[u] != INF && dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
                parent[e.to] = u;
                pq.push({e.to, dist[e.to]});
            }
        }
    }
}

std::vector<int> buildPath(int target, const std::vector<int> &parent) {
    std::vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    std::cout << "===== Dijkstra Shortest Path with Reconstruction Demo =====\n";

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of edges: ";
    std::cin >> m;

    if (n <= 0 || m < 0) {
        std::cout << "Invalid input. Exiting.\n";
        return 0;
    }

    std::vector<std::vector<Edge>> adj(n);

    std::cout << "Enter edges in the form: u v w (directed edge u -> v with non-negative weight w)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n || w < 0) {
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

    std::vector<int> dist, parent;
    dijkstraWithPath(n, adj, src, dist, parent);

    const int INF = std::numeric_limits<int>::max();

    std::cout << "Shortest distances and paths from source " << src << ":\n";
    for (int v = 0; v < n; ++v) {
        std::cout << "Vertex " << v << ": ";
        if (dist[v] == INF) {
            std::cout << "INF (unreachable)\n";
            continue;
        }
        std::cout << "distance = " << dist[v] << ", path = ";
        std::vector<int> path = buildPath(v, parent);
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i + 1 < path.size()) std::cout << " -> ";
        }
        std::cout << '\n';
    }

    return 0;
}
