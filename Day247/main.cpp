#include <iostream>
#include <vector>
using namespace std;

// Medium level DSA: Count number of islands in a grid using DFS
// 1 = land, 0 = water, connected 4-directionally (up, down, left, right)

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> vis;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (inside(nx, ny) && !vis[nx][ny] && grid[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Count Islands in a Grid (DFS)\n";
    cout << "Enter rows and columns: ";
    if (!(cin >> n >> m) || n <= 0 || m <= 0) return 0;

    grid.assign(n, vector<int>(m));
    vis.assign(n, vector<bool>(m, false));

    cout << "Enter grid (" << n << " rows of " << m << " values: 0 or 1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int islands = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] == 1) {
                ++islands;
                dfs(i, j);
            }
        }
    }

    cout << "Number of islands: " << islands << "\n";
    return 0;
}
