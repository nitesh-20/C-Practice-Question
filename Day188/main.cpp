#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Dijkstra's shortest path algorithm (medium level DSA)
// This program finds shortest distances from a source vertex to all other vertices

const int INF = 1e9;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src}); // {distance, vertex}
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue; // already processed with better distance
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    cout << "Dijkstra's Shortest Path Algorithm\n";
    cout << "Enter number of vertices: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    
    cout << "Enter number of edges: ";
    int m;
    if (!(cin >> m) || m < 0) return 0;
    
    vector<vector<pair<int,int>>> adj(n);
    cout << "Enter " << m << " edges (format: from to weight):\n";
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex indices!\n";
            return 0;
        }
        adj[u].push_back({v, w});
        // For undirected graph, uncomment the next line:
        // adj[v].push_back({u, w});
    }
    
    cout << "Enter source vertex: ";
    int src;
    if (!(cin >> src) || src < 0 || src >= n) {
        cout << "Invalid source vertex!\n";
        return 0;
    }
    
    vector<int> distances = dijkstra(n, adj, src);
    
    cout << "\nShortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To vertex " << i << ": ";
        if (distances[i] == INF) cout << "unreachable\n";
        else cout << distances[i] << "\n";
    }
    
    return 0;
}