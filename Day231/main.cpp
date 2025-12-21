#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Minimum Spanning Tree (MST) using Prim's Algorithm
// Graph is undirected, weighted, and connected (or we will get MST for its component).
// Time complexity: O((V + E) log V) using priority_queue.

struct Edge {
    int to;
    int weight;
};

struct Node {
    int vertex;
    int weight;
    bool operator>(const Node &other) const {
        return weight > other.weight;
    }
};

int primMST(int n, const std::vector<std::vector<Edge>> &adj, int start = 0) {
    const int INF = std::numeric_limits<int>::max();
    std::vector<bool> inMST(n, false);
    std::vector<int> minEdge(n, INF);
    minEdge[start] = 0;

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({start, 0});

    int totalWeight = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += node.weight;

        for (const auto &e : adj[u]) {
            if (!inMST[e.to] && e.weight < minEdge[e.to]) {
                minEdge[e.to] = e.weight;
                pq.push({e.to, e.weight});
            }
        }
    }

    // Check if all vertices are in MST
    for (int i = 0; i < n; ++i) {
        if (!inMST[i]) {
            std::cout << "Graph is not connected. MST not possible for all vertices.\n";
            break;
        }
    }

    return totalWeight;
}

int main() {
    std::cout << "===== Prim's Algorithm MST Demo =====\n";

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

    std::cout << "Enter edges in the form: u v w (undirected edge between u and v with weight w)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            std::cout << "Invalid edge, skipping.\n";
            continue;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    int start = 0;
    std::cout << "Enter starting vertex for MST (0 to " << n - 1 << ", default 0): ";
    if (!(std::cin >> start)) {
        start = 0;
    }

    if (start < 0 || start >= n) {
        std::cout << "Invalid start vertex, using 0 by default.\n";
        start = 0;
    }

    int totalWeight = primMST(n, adj, start);

    std::cout << "Total weight of MST: " << totalWeight << "\n";

    return 0;
}
