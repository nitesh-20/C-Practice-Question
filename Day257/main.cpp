#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Medium level DSA: Detect and print cycles in a directed graph using DFS.
// We track a recursion stack path; when we see a back edge, we output that cycle.

void dfs(int u,
         const vector<vector<int>> &adj,
         vector<int> &color,        // 0 = unvisited, 1 = in stack, 2 = done
         vector<int> &parent,
         vector<vector<int>> &cycles) {
    color[u] = 1; // in recursion stack

    for (int v : adj[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            dfs(v, adj, color, parent, cycles);
        } else if (color[v] == 1) {
            // back edge found: u -> v, record this cycle
            vector<int> cycle;
            int cur = u;
            cycle.push_back(v);
            while (cur != v && cur != -1) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            if (!cycle.empty() && cur == v) {
                // complete the cycle path from v back to v
                // currently cycle = [v, ..., u]; reverse to start at v
                reverse(cycle.begin() + 1, cycle.end());
                cycles.push_back(cycle);
            }
        }
    }

    color[u] = 2; // done
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== Detect Cycles in Directed Graph (DFS) =====\n";

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

    vector<vector<int>> adj(n);
    cout << "Enter edges as: u v (directed edge u -> v), vertices 0.." << n - 1 << "\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge, skipping.\n";
            continue;
        }
        adj[u].push_back(v);
    }

    vector<int> color(n, 0);
    vector<int> parent(n, -1);
    vector<vector<int>> cycles;

    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(i, adj, color, parent, cycles);
        }
    }

    if (cycles.empty()) {
        cout << "No cycles found in the directed graph.\n";
    } else {
        cout << "Cycles found (each printed as a sequence of vertices):\n";
        int idx = 1;
        for (const auto &cycle : cycles) {
            cout << "Cycle " << idx++ << ": ";
            for (size_t i = 0; i < cycle.size(); ++i) {
                cout << cycle[i];
                if (i + 1 < cycle.size()) cout << " -> ";
            }
            cout << "\n";
        }
    }

    return 0;
}
