// ...existing code...
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Easy DSA demo: Rotate an array to the right by k positions (in-place)
// Uses the reverse-method: reverse whole, reverse first k, reverse rest.

void rotateRight(vector<int>& a, int k) {
    int n = static_cast<int>(a.size());
    if (n == 0) return;
    k %= n;
    if (k < 0) k += n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
}

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    cout << "Rotate Array Demo\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n < 0) return 0;

    vector<int> a(n);
    if (n > 0) {
        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; ++i) cin >> a[i];
    }

    cout << "Enter k (rotate right by k): ";
    int k;
    if (!(cin >> k)) return 0;

    cout << "Original array: ";
    printArray(a);

    rotateRight(a, k);

    cout << "Array after rotating right by " << k << ": ";
    printArray(a);

    return 0;
}
