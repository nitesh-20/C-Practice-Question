#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 0-1 BFS for shortest path (when edge weights are 0 or 1)
// Uses deque: add to front if edge weight is 0, back if weight is 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "0-1 BFS Shortest Path\n";
    cout << "Enter number of vertices (n) and edges (m): ";
    int n, m;
    if (!(cin >> n >> m) || n <= 0 || m < 0) return 0;

    vector<vector<pair<int,int>>> adj(n); // {neighbor, weight}
    cout << "Enter " << m << " edges as: u v w (0-based, w should be 0 or 1)\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n || (w != 0 && w != 1)) {
            cout << "Invalid edge: " << u << " " << v << " " << w << "\n";
            return 0;
        }
        adj[u].push_back({v, w});
        // For undirected graph, uncomment next line:
        // adj[v].push_back({u, w});
    }

    cout << "Enter source vertex (0-based): ";
    int src;
    if (!(cin >> src) || src < 0 || src >= n) {
        cout << "Invalid source vertex\n";
        return 0;
    }

    vector<int> dist(n, -1);
    deque<int> dq;
    dist[src] = 0;
    dq.push_back(src);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[v] == -1 || dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To " << i << ": ";
        if (dist[i] == -1) cout << "unreachable\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}