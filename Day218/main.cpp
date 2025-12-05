#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Check if an undirected graph is bipartite using BFS coloring

bool isBipartite(int n, const vector<vector<int>>& adj) {
    vector<int> color(n, -1); // -1 = uncolored, 0 and 1 are two colors
    
    for (int start = 0; start < n; ++start) {
        if (color[start] != -1) continue; // already colored via previous BFS
        
        queue<int> q;
        color[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false; // conflict
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Check if Graph is Bipartite (Undirected)\n";
    cout << "Enter number of vertices and edges: ";
    int n, m;
    if (!(cin >> n >> m) || n <= 0 || m < 0) return 0;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " edges (u v) with 0-based indices:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge indices.\n";
            return 0;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    if (isBipartite(n, adj)) cout << "The graph IS bipartite.\n";
    else cout << "The graph is NOT bipartite.\n";

    return 0;
}