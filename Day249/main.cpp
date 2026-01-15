#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Medium level DSA: Shortest path in an unweighted grid (maze) using BFS
// 0 = free cell, 1 = blocked. Move in 4 directions.
// Find shortest path from (0,0) to (n-1,m-1) and print distance and one path.

struct Cell {
    int x, y;
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inside(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Shortest Path in Grid (BFS)\n";

    int n, m;
    cout << "Enter rows and columns: ";
    if (!(cin >> n >> m) || n <= 0 || m <= 0) {
        cout << "Invalid input. Exiting.\n";
        return 0;
    }

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid (" << n << " rows of " << m << " values: 0 = free, 1 = blocked):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
        cout << "Start or end cell is blocked. No path.\n";
        return 0;
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<Cell>> parent(n, vector<Cell>(m, {-1, -1}));

    queue<Cell> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();

        if (cur.x == n - 1 && cur.y == m - 1) break; // reached target

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (!inside(nx, ny, n, m)) continue;
            if (grid[nx][ny] == 1) continue; // blocked
            if (dist[nx][ny] != -1) continue; // already visited

            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            parent[nx][ny] = cur;
            q.push({nx, ny});
        }
    }

    if (dist[n-1][m-1] == -1) {
        cout << "No path from (0,0) to (" << n-1 << "," << m-1 << ").\n";
    } else {
        cout << "Shortest distance: " << dist[n-1][m-1] << "\n";

        // Reconstruct path
        vector<Cell> path;
        Cell cur = {n-1, m-1};
        while (!(cur.x == -1 && cur.y == -1)) {
            path.push_back(cur);
            Cell p = parent[cur.x][cur.y];
            cur = p.x == -1 && p.y == -1 ? Cell{-1, -1} : p;
        }

        reverse(path.begin(), path.end());

        cout << "Path (x,y): ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << "(" << path[i].x << "," << path[i].y << ")";
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << "\n";
    }

    return 0;
}
