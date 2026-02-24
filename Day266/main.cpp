// Two BFS examples in one file.
// Choice 1: BFS traversal (prints BFS order)
// Input format for choice 1:
// 1
// n m
// m lines: u v (undirected edges, 1-based)
// start
// Example:
// 1
// 5 4
// 1 2
// 1 3
// 2 4
// 3 5
// 1

// Choice 2: BFS shortest path in unweighted graph
// Input format for choice 2:
// 2
// n m
// m lines: u v (undirected edges, 1-based)
// s t
// Example:
// 2
// 6 5
// 1 2
// 2 3
// 1 4
// 4 5
// 5 6
// 1 6

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



void bfs_traversal() {
	int n, m;
	if (!(cin >> n >> m)) return;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int start; cin >> start;
	vector<int> vis(n + 1, 0);
	queue<int> q;
	q.push(start); vis[start] = 1;
	vector<int> order;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		order.push_back(u);
		for (int v : adj[u]) if (!vis[v]) { vis[v] = 1; q.push(v); }
	}
	for (size_t i = 0; i < order.size(); ++i) {
		if (i) cout << ' ';
		cout << order[i];
	}
	cout << '\n';
}

void bfs_shortest_path() {
	int n, m;
	if (!(cin >> n >> m)) return;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s, t; cin >> s >> t;
	vector<int> dist(n + 1, -1), par(n + 1, -1);
	queue<int> q;
	dist[s] = 0; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				par[v] = u;
				q.push(v);
			}
		}
	}
	if (dist[t] == -1) {
		cout << "-1\n"; // unreachable
		return;
	}
	cout << dist[t] << '\n';
	vector<int> path;
	for (int cur = t; cur != -1; cur = par[cur]) path.push_back(cur);
	reverse(path.begin(), path.end());
	for (size_t i = 0; i < path.size(); ++i) {
		if (i) cout << ' ';
		cout << path[i];
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int choice;
	if (!(cin >> choice)) return 0;
	if (choice == 1) bfs_traversal();
	else if (choice == 2) bfs_shortest_path();
	return 0;
}
