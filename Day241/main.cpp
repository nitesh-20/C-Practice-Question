#include <iostream>
#include <vector>

// 2D Binary Indexed Tree (Fenwick Tree)
// Supports:
//  - point update: add value to cell (x, y)
//  - submatrix sum query: sum over rectangle [x1..x2][y1..y2]
// Time complexity: O(log n * log m) per operation.

class FenwickTree2D {
public:
    FenwickTree2D(int n, int m) : n(n), m(m), bit(n + 1, std::vector<int>(m + 1, 0)) {}

    // Add 'delta' to cell (x, y) (0-based indices)
    void update(int x, int y, int delta) {
        for (int i = x + 1; i <= n; i += i & -i) {
            for (int j = y + 1; j <= m; j += j & -j) {
                bit[i][j] += delta;
            }
        }
    }

    // Prefix sum from (0,0) to (x,y) inclusive (0-based indices)
    int prefixSum(int x, int y) const {
        int res = 0;
        for (int i = x + 1; i > 0; i -= i & -i) {
            for (int j = y + 1; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }
        return res;
    }

    // Sum over submatrix [x1..x2][y1..y2] (0-based inclusive)
    int rangeSum(int x1, int y1, int x2, int y2) const {
        if (x1 > x2 || y1 > y2) return 0;
        int A = prefixSum(x2, y2);
        int B = (x1 > 0) ? prefixSum(x1 - 1, y2) : 0;
        int C = (y1 > 0) ? prefixSum(x2, y1 - 1) : 0;
        int D = (x1 > 0 && y1 > 0) ? prefixSum(x1 - 1, y1 - 1) : 0;
        return A - B - C + D;
    }

private:
    int n, m;
    std::vector<std::vector<int>> bit; // 1-based internal 2D array
};

int main() {
    std::cout << "===== 2D Fenwick Tree (Binary Indexed Tree) Demo =====\n";

    int n, m;
    std::cout << "Enter number of rows: ";
    std::cin >> n;
    std::cout << "Enter number of columns: ";
    std::cin >> m;

    if (n <= 0 || m <= 0) {
        std::cout << "Invalid dimensions. Exiting.\n";
        return 0;
    }

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::cout << "Enter matrix elements (" << n << "x" << m << ") row-wise:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    FenwickTree2D ft(n, m);
    // Build tree with initial values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ft.update(i, j, a[i][j]);
        }
    }

    std::cout << "Commands:\n";
    std::cout << " 1 x1 y1 x2 y2 -> submatrix sum query over [x1..x2][y1..y2] (0-based)\n";
    std::cout << " 2 x y v       -> add v to cell (x, y) (point update)\n";
    std::cout << " 0             -> exit\n";

    while (true) {
        int type;
        std::cout << "Enter command type (0/1/2): ";
        if (!(std::cin >> type)) break;

        if (type == 0) {
            std::cout << "Exiting...\n";
            break;
        } else if (type == 1) {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 ||
                x1 >= n || x2 >= n || y1 >= m || y2 >= m ||
                x1 > x2 || y1 > y2) {
                std::cout << "Invalid rectangle.\n";
                continue;
            }
            std::cout << "Sum of a[" << x1 << ".." << x2 << "][" << y1 << ".." << y2
                      << "] = " << ft.rangeSum(x1, y1, x2, y2) << "\n";
        } else if (type == 2) {
            int x, y, v;
            std::cin >> x >> y >> v;
            if (x < 0 || x >= n || y < 0 || y >= m) {
                std::cout << "Invalid cell.\n";
                continue;
            }
            a[x][y] += v;
            ft.update(x, y, v);
            std::cout << "Updated a[" << x << "][" << y << "] to " << a[x][y] << "\n";
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }

    return 0;
}
