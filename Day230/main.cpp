#include <iostream>
#include <vector>
#include <algorithm>

// Longest Increasing Subsequence (LIS)
// Efficient O(n log n) algorithm ("patience sorting" idea) with reconstruction

std::vector<int> LIS(const std::vector<int> &a) {
    int n = static_cast<int>(a.size());
    if (n == 0) return {};

    // tails[len] = index of the smallest tail of any increasing subsequence of length len+1
    std::vector<int> tails;
    std::vector<int> prev(n, -1); // prev[index] = previous index in LIS ending at index

    std::vector<int> tailIdx; // tailIdx[len] = index in a of tail element

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        // Find position with lower_bound on values in tailIdx
        int l = 0, r = static_cast<int>(tailIdx.size());
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[tailIdx[mid]] < x) l = mid + 1;
            else r = mid;
        }

        if (l > 0) prev[i] = tailIdx[l - 1];

        if (l == static_cast<int>(tailIdx.size())) {
            tailIdx.push_back(i);
        } else {
            tailIdx[l] = i;
        }
    }

    // Reconstruct LIS
    std::vector<int> lis;
    int idx = tailIdx.back();
    while (idx != -1) {
        lis.push_back(a[idx]);
        idx = prev[idx];
    }
    std::reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    std::cout << "===== Longest Increasing Subsequence (LIS) Demo =====\n";

    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid size. Exiting.\n";
        return 0;
    }

    std::vector<int> a(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> lis = LIS(a);

    std::cout << "Length of LIS: " << lis.size() << "\n";
    std::cout << "One Longest Increasing Subsequence: ";
    for (size_t i = 0; i < lis.size(); ++i) {
        std::cout << lis[i] << (i + 1 < lis.size() ? ' ' : '\n');
    }

    return 0;
}
