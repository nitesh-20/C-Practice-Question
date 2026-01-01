#include <iostream>
#include <vector>

// Binary Indexed Tree (Fenwick Tree)
// Supports:
//  - point update: add value to index i
//  - prefix sum query: sum of [0..i]
// Time complexity: O(log n) per operation.

class FenwickTree {
public:
    explicit FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    // Add 'delta' to index i (0-based index)
    void update(int i, int delta) {
        for (int idx = i + 1; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    // Prefix sum from 0 to i (0-based index)
    int prefixSum(int i) const {
        int res = 0;
        for (int idx = i + 1; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }
        return res;
    }

    // Range sum [l, r] (0-based inclusive)
    int rangeSum(int l, int r) const {
        if (l > r) return 0;
        return prefixSum(r) - (l > 0 ? prefixSum(l - 1) : 0);
    }

private:
    int n;
    std::vector<int> bit; // 1-based internal array
};

int main() {
    std::cout << "===== Fenwick Tree (Binary Indexed Tree) Demo =====\n";

    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid size. Exiting.\n";
        return 0;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    FenwickTree ft(n);
    for (int i = 0; i < n; ++i) {
        ft.update(i, arr[i]);
    }

    std::cout << "Commands:\n";
    std::cout << " 1 l r  -> range sum query from l to r (0-based, inclusive)\n";
    std::cout << " 2 i x  -> add x to element at index i (point update)\n";
    std::cout << " 0      -> exit\n";

    while (true) {
        int type;
        std::cout << "Enter command type (0/1/2): ";
        if (!(std::cin >> type)) break;

        if (type == 0) {
            std::cout << "Exiting...\n";
            break;
        } else if (type == 1) {
            int l, r;
            std::cin >> l >> r;
            if (l < 0 || r < 0 || l >= n || r >= n || l > r) {
                std::cout << "Invalid range.\n";
                continue;
            }
            std::cout << "Sum of arr[" << l << ".." << r << "] = " << ft.rangeSum(l, r) << "\n";
        } else if (type == 2) {
            int i, x;
            std::cin >> i >> x;
            if (i < 0 || i >= n) {
                std::cout << "Invalid index.\n";
                continue;
            }
            arr[i] += x;
            ft.update(i, x);
            std::cout << "Updated arr[" << i << "] to " << arr[i] << "\n";
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }

    return 0;
}
