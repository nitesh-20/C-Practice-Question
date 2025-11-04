#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, rankv;
    DSU(int n=0): n(n), parent(n), rankv(n,0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Kruskal's MST (Disjoint Set Union)\n";
    cout << "Enter number of vertices (n) and edges (m): ";
    int n, m;
    if (!(cin >> n >> m) || n <= 0 || m < 0) return 0;

    cout << "Enter " << m << " edges as: u v w (0-based indices)\n";
    struct Edge { int u,v; long long w; };
    vector<Edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u,v; long long w;
        cin >> u >> v >> w;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex index in edge " << i+1 << "\n";
            return 0;
        }
        edges.push_back({u,v,w});
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){ return a.w < b.w; });

    DSU dsu(n);
    long long total = 0;
    vector<Edge> mst;
    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            total += e.w;
            if ((int)mst.size() == n-1) break;
        }
    }

    if ((int)mst.size() != n-1) {
        cout << "MST not possible (graph is disconnected).\n";
    } else {
        cout << "MST total weight: " << total << "\n";
        cout << "Edges in MST (u v w):\n";
        for (auto &e : mst) cout << e.u << ' ' << e.v << ' ' << e.w << "\n";
    }

    return 0;
}