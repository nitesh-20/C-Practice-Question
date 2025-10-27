// ...existing code...
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Simple demo: Linear Search and Binary Search (easy DSA)

int linearSearch(const vector<int>& a, int target) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == target) return static_cast<int>(i);
    }
    return -1;
}

int binarySearch(const vector<int>& a, int target) {
    int l = 0, r = static_cast<int>(a.size()) - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == target) return m;
        if (a[m] < target) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    cout << "Linear Search and Binary Search Demo\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> a(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Enter target to search: ";
    int target;
    if (!(cin >> target)) return 0;

    int idxLinear = linearSearch(a, target);
    if (idxLinear != -1) cout << "Linear Search: Found at index " << idxLinear << " (0-based)\n";
    else cout << "Linear Search: Not found\n";

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    cout << "Sorted array: ";
    for (int x : sorted) cout << x << " ";
    cout << "\n";

    int idxBinary = binarySearch(sorted, target);
    if (idxBinary != -1) cout << "Binary Search: Found at sorted-index " << idxBinary << " (0-based)\n";
    else cout << "Binary Search: Not found\n";

    return 0;
}
// ...existing code...
```// filepath: /Users/niteshsahu/Desktop/C-Practice-Question/Day205/main.cpp
// ...existing code...
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Simple demo: Linear Search and Binary Search (easy DSA)

int linearSearch(const vector<int>& a, int target) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == target) return static_cast<int>(i);
    }
    return -1;
}

int binarySearch(const vector<int>& a, int target) {
    int l = 0, r = static_cast<int>(a.size()) - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == target) return m;
        if (a[m] < target) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    cout << "Linear Search and Binary Search Demo\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> a(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Enter target to search: ";
    int target;
    if (!(cin >> target)) return 0;

    int idxLinear = linearSearch(a, target);
    if (idxLinear != -1) cout << "Linear Search: Found at index " << idxLinear << " (0-based)\n";
    else cout << "Linear Search: Not found\n";

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    cout << "Sorted array: ";
    for (int x : sorted) cout << x << " ";
    cout << "\n";

    int idxBinary = binarySearch(sorted, target);
    if (idxBinary != -1) cout << "Binary Search: Found at sorted-index " << idxBinary << " (0-based)\n";
    else cout << "Binary Search: Not found\n";

    return 0;