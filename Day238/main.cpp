#include <iostream>
#include <vector>
#include <stack>

// Strongly Connected Components (SCCs) in a directed graph
// Kosaraju's algorithm: two DFS passes
// Time complexity: O(V + E)

void dfs1(int u, const std::vector<std::vector<int>> &adj, std::vector<bool> &vis, std::stack<int> &st) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs1(v, adj, vis, st);
    }
    st.push(u); // finish time order
}

void dfs2(int u, const std::vector<std::vector<int>> &radj, std::vector<bool> &vis, std::vector<int> &component) {
    vis[u] = true;
    component.push_back(u);
    for (int v : radj[u]) {
        if (!vis[v]) dfs2(v, radj, vis, component);
    }
}

int main() {
    std::cout << "===== Strongly Connected Components (Kosaraju) Demo =====\n";

    int n, m;
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    std::cout << "Enter number of directed edges: ";
    std::cin >> m;

    if (n <= 0 || m < 0) {
        std::cout << "Invalid input. Exiting.\n";
        return 0;
    }

    std::vector<std::vector<int>> adj(n), radj(n);

    std::cout << "Enter edges in the form: u v (directed edge u -> v)\n";
    std::cout << "Vertices are 0-based indices [0, " << n - 1 << "]: \n";

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            std::cout << "Invalid edge, skipping.\n";
            continue;
        }
        adj[u].push_back(v);
        radj[v].push_back(u); // reverse graph
    }

    // 1st DFS pass: order vertices by finish time
    std::vector<bool> vis(n, false);
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs1(i, adj, vis, st);
    }

    // 2nd DFS pass on reversed graph in decreasing finish time
    std::fill(vis.begin(), vis.end(), false);

    int sccCount = 0;
    std::cout << "Strongly Connected Components:\n";

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!vis[v]) {
            std::vector<int> component;
            dfs2(v, radj, vis, component);
            ++sccCount;

            std::cout << "SCC " << sccCount << ": ";
            for (int node : component) {
                std::cout << node << ' ';
            }
            std::cout << '\n';
        }
    }

    std::cout << "Total number of SCCs: " << sccCount << "\n";

    return 0;
}
