#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Maximum Flow using Edmonds-Karp algorithm (BFS-based Ford-Fulkerson)
// Time complexity: O(V * E^2) in worst case.

bool bfs(int n, const std::vector<std::vector<int>> &residual,
         int s, int t, std::vector<int> &parent) {
    std::fill(parent.begin(), parent.end(), -1);
    parent[s] = -2; // mark source as visited with special value

    std::queue<std::pair<int, int>> q; // (vertex, flow so far)
    q.push({s, std::numeric_limits<int>::max()});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                int newFlow = std::min(flow, residual[u][v]);
                if (v == t) {
                    return true; // path found; parent holds the path
                }
                q.push({v, newFlow});
            }
        }
    }

    return false; // no augmenting path
}

int maxFlow(int n, std::vector<std::vector<int>> residual, int s, int t) {
    int flow = 0;
    std::vector<int> parent(n);

    while (bfs(n, residual, s, t, parent)) {
        // Find bottleneck capacity along the path
        int bottleneck = std::numeric_limits<int>::max();
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            bottleneck = std::min(bottleneck, residual[prev][cur]);
            cur = prev;
        }

        // Update residual capacities
        cur = t;
        while (cur != s) {
            int prev = parent[cur];
            residual[prev][cur] -= bottleneck;
            residual[cur][prev] += bottleneck; // reverse edge
            cur = prev;
        }

        flow += bottleneck;
    }

    return flow;
}

int main() {
    std::cout << "===== Edmonds-Karp Maximum Flow Demo =====\n";

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of directed edges: ";
    std::cin >> m;

    if (n <= 0 || m < 0) {
        std::cout << "Invalid input. Exiting.\n";
        return 0;
    }

    std::vector<std::vector<int>> capacity(n, std::vector<int>(n, 0));

    std::cout << "Enter edges in the form: u v c (directed edge u -> v with capacity c)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        if (u < 0 || u >= n || v < 0 || v >= n || c < 0) {
            std::cout << "Invalid edge, skipping.\n";
            continue;
        }
        capacity[u][v] += c; // if multiple edges, accumulate capacity
    }

    int s, t;
    std::cout << "Enter source vertex: ";
    std::cin >> s;
    std::cout << "Enter sink vertex: ";
    std::cin >> t;

    if (s < 0 || s >= n || t < 0 || t >= n) {
        std::cout << "Invalid source/sink. Exiting.\n";
        return 0;
    }

    int result = maxFlow(n, capacity, s, t);

    std::cout << "Maximum possible flow from " << s << " to " << t << " is: " << result << "\n";

    return 0;
}
