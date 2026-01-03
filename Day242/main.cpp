#include <iostream>
#include <vector>
#include <algorithm>

// Meet-in-the-middle Subset Sum Count
// Given n numbers and a target S, count how many subsets have sum exactly S.
// Uses meet-in-the-middle: split array into two halves, enumerate sums, and combine.
// Complexity: O(2^(n/2) * n), good for n up to ~40.

void genSums(const std::vector<long long> &a, int l, int r, std::vector<long long> &sums) {
    int len = r - l + 1;
    int total = 1 << len; // 2^len subsets
    sums.reserve(total);
    for (int mask = 0; mask < total; ++mask) {
        long long sum = 0;
        for (int i = 0; i < len; ++i) {
            if (mask & (1 << i)) sum += a[l + i];
        }
        sums.push_back(sum);
    }
}

int main() {
    std::cout << "===== Meet-in-the-middle Subset Sum Count Demo =====\n";

    int n;
    std::cout << "Enter number of elements (<= 40 recommended): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid size. Exiting.\n";
        return 0;
    }

    std::vector<long long> a(n);
    std::cout << "Enter " << n << " integers (can be positive or negative): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long target;
    std::cout << "Enter target sum S: ";
    std::cin >> target;

    int mid = n / 2;
    std::vector<long long> leftSums, rightSums;

    // Generate all subset sums for left half [0..mid-1]
    genSums(a, 0, mid - 1, leftSums);

    // Generate all subset sums for right half [mid..n-1]
    genSums(a, mid, n - 1, rightSums);

    // Sort right sums for binary search
    std::sort(rightSums.begin(), rightSums.end());

    long long count = 0;

    // For each left sum x, we need y = target - x from rightSums
    for (long long x : leftSums) {
        long long need = target - x;
        auto range = std::equal_range(rightSums.begin(), rightSums.end(), need);
        count += (range.second - range.first);
    }

    std::cout << "Number of subsets with sum exactly " << target << " is: " << count << "\n";

    return 0;
}
