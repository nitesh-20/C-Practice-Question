// Binary search example
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
using namespace std;

int binary_search_idx(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // n
    // a[0] a[1] ... a[n-1]   (sorted ascending)
    // q
    // x1
    // x2
    // ...

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        int idx = binary_search_idx(a, x);
        if (idx == -1) cout << "Not found\n";
        
        else cout << idx << '\n';
    }


    return 0;
}
