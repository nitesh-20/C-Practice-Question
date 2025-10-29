#include <iostream>
#include <vector>
using namespace std;

long long mergeCount(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long inv = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else {
            a[k++] = R[j++];
            inv += (n1 - i); // all remaining in L are inversions
        }
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    return inv;
}

long long sortCount(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    long long inv = 0;
    inv += sortCount(a, l, m);
    inv += sortCount(a, m + 1, r);
    inv += mergeCount(a, l, m, r);
    return inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Inversion Count (using merge sort)\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    vector<int> a(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long inversions = sortCount(a, 0, n - 1);
    cout << "Number of inversions: " << inversions << "\n";
    return 0;
}