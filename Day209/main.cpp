#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Topological Sort (Kahn's algorithm)\n";
    cout << "Enter number of vertices (n) and edges (m): ";
    int n, m;
    if (!(cin >> n >> m) || n <= 0 || m < 0) return 0;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    cout << "Enter " << m << " directed edges (u v) with 0-based indices:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge indices.\n";
            return 0;
        }
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    if ((int)topo.size() != n) {
        cout << "Cycle detected — topological order not possible.\n";
    } else {
        cout << "Topological order:\n";
        for (int x : topo) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}