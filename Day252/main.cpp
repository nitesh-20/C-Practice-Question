#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// Medium level DSA: Binary search on answer
// Problem: Given weights of packages in order and D days, find the minimum ship
// capacity so that all packages can be shipped within D days, preserving order.

bool canShip(const vector<int> &w, int D, int cap) {
    int days = 1;
    int cur = 0;
    for (int x : w) {
        if (x > cap) return false; // impossible, capacity too small
        if (cur + x <= cap) {
            cur += x;
        } else {
            ++days;
            cur = x;
            
            if (days > D) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== Minimum Capacity to Ship Packages Within D Days (Binary Search) =====\n";

    int n;
    cout << "Enter number of packages: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n. Exiting.\n";
        return 0;
    }

    vector<int> w(n);
    cout << "Enter " << n << " package weights: ";
    for (int i = 0; i < n; ++i) cin >> w[i];

    int D;
    cout << "Enter number of days D: ";
    cin >> D;
    if (D <= 0) {
        cout << "Invalid D. Exiting.\n";
        return 0;
    }

    int low = *max_element(w.begin(), w.end());
    int high = accumulate(w.begin(), w.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(w, D, mid)) {
            ans = mid;
            high = mid - 1; // try smaller capacity
        } else {
            low = mid + 1; // need larger capacity
        }
    }

    cout << "Minimum capacity required: " << ans << "\n";

    return 0;
}
