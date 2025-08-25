#include <iostream>
#include <vector>
using namespace std;

// Kadane's Algorithm - Maximum Subarray Sum
// Reads n and an array of n integers, outputs maximum subarray sum and the subarray.

int main() {
    cout << "Kadane's Algorithm - Maximum Subarray Sum\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    vector<long long> a(n);
    cout << "Enter " << n << " elements separated by space:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long maxSoFar = a[0];
    long long maxEndingHere = a[0];
    int start = 0, end = 0, s = 0;

    for (int i = 1; i < n; ++i) {
        if (maxEndingHere + a[i] < a[i]) {
            maxEndingHere = a[i];
            s = i;
        } else {
            maxEndingHere += a[i];
        }
        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }
    }

    cout << "Maximum subarray sum: " << maxSoFar << "\n";
    cout << "Subarray (indices " << start << " to " << end << "): ";
    for (int i = start; i <= end; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
