#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstdio>
using namespace std;

// Merge Sort implementation
void merge(vector<long long> &a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<long long> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(vector<long long> &a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

// Iterative binary search: returns index (0-based) or -1 if not found
int binarySearch(const vector<long long> &a, long long key) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Program usage:
    // Input:
    // n
    // n numbers
    // q (number of queries)
    // q lines, each a number to search

    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    mergeSort(a, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    int q;
    cin >> q;
    while (q--) {
        long long x; cin >> x;
        int idx = binarySearch(a, x);
        if (idx == -1) cout << x << " not found\n";
        else cout << x << " found at index " << idx << " (0-based)\n";
    }

    return 0;
}
