#include <iostream>
#include <vector>
#include <deque>
#include <limits>

// 0-1 BFS on a grid
// Each cell has cost 0 or 1 to enter; find minimum cost path from (0,0) to (n-1,m-1)
// using a deque. Time: O(n * m).

struct Cell {
    int x, y;
};

int main() {
    std::cout << "===== 0-1 BFS on Grid (Shortest Path) Demo =====\n";

    int n, m;
    std::cout << "Enter number of rows: ";
    std::cin >> n;
    std::cout << "Enter number of columns: ";
    std::cin >> m;

    if (n <= 0 || m <= 0) {
        std::cout << "Invalid dimensions. Exiting.\n";
        return 0;
    }

    std::vector<std::vector<int>> cost(n, std::vector<int>(m));
    std::cout << "Enter grid costs (0 or 1) row-wise:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> cost[i][j];
            if (cost[i][j] != 0 && cost[i][j] != 1) {
                std::cout << "Invalid cost, forcing to 1.\n";
                cost[i][j] = 1;
            }
        }
    }

    const int INF = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, INF));
    std::deque<Cell> dq;

    dist[0][0] = cost[0][0];
    dq.push_front({0, 0});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!dq.empty()) {
        Cell u = dq.front();
        dq.pop_front();

        int x = u.x, y = u.y;
        int currentDist = dist[x][y];

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int w = cost[nx][ny]; // weight of moving into neighbor (0 or 1)
            if (currentDist + w < dist[nx][ny]) {
                dist[nx][ny] = currentDist + w;
                if (w == 0) {
                    dq.push_front({nx, ny});
                } else {
                    dq.push_back({nx, ny});
                }
            }
        }
    }

    if (dist[n - 1][m - 1] == INF) {
        std::cout << "Target cell is unreachable.\n";
    } else {
        std::cout << "Minimum cost from (0,0) to (" << n - 1 << "," << m - 1
                  << ") is: " << dist[n - 1][m - 1] << "\n";
    }

    return 0;
}
