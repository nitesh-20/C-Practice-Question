#include <bits/stdc++.h>
using namespace std;
// Longest Increasing Subsequence (LIS) - O(n log n) with reconstruction
// Input:
// n
// a1 a2 ... an
// Output:
// length_of_LIS
// one LIS sequence (space separated)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // tail[i] will hold the smallest possible tail value of an increasing
    // subsequence of length i+1. tail_idx stores the original index.
    vector<long long> tail;
    vector<int> tail_idx; // indices in original array
    vector<int> parent(n, -1); // for reconstruction

    for (int i = 0; i < n; ++i) {
        long long x = a[i];
        auto it = lower_bound(tail.begin(), tail.end(), x);
        int pos = (int)(it - tail.begin());

        if (it == tail.end()) {
            tail.push_back(x);
            tail_idx.push_back(i);
        } else {
            *it = x;
            tail_idx[pos] = i;
        }

        if (pos > 0) parent[i] = tail_idx[pos - 1];
        // ensure tail_idx[pos] is current index (already set above)
    }

    int lis_len = (int)tail.size();

    // Reconstruct one LIS: start from tail_idx[lis_len-1]
    vector<long long> lis;
    int cur = tail_idx.empty() ? -1 : tail_idx[lis_len - 1];
    while (cur != -1) {
        lis.push_back(a[cur]);
        cur = parent[cur];
    }
    reverse(lis.begin(), lis.end());

    cout << lis_len << '\n';
    for (size_t i = 0; i < lis.size(); ++i) {
        if (i) cout << ' ';
        cout << lis[i];
    }
    cout << '\n';

    return 0;
}
