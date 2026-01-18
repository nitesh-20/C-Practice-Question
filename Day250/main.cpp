#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Medium level DSA: Kadane's Algorithm
// Find the maximum subarray sum and its start/end indices.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== Kadane's Algorithm: Maximum Subarray Sum =====\n";

    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid size. Exiting.\n";
        return 0;
    }

    vector<long long> a(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long bestSum = numeric_limits<long long>::min();
    long long currentSum = 0;
    int bestL = 0, bestR = 0;
    int curL = 0;

    for (int i = 0; i < n; ++i) {
        if (currentSum <= 0) {
            currentSum = a[i];
            curL = i;
        } else {
            currentSum += a[i];
        }

        if (currentSum > bestSum) {
            bestSum = currentSum;
            bestR = i;
            bestL = curL;
        }
    }

    cout << "Maximum subarray sum = " << bestSum << "\n";
    cout << "Subarray indices: from " << bestL << " to " << bestR << " (0-based)\n";
    cout << "Subarray elements: ";
    for (int i = bestL; i <= bestR; ++i) {
        cout << a[i] << (i < bestR ? ' ' : '\n');
    }

    return 0;
}
