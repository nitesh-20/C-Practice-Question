#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Top K Frequent Elements\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> a(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Enter k: ";
    int k;
    cin >> k;
    if (k <= 0) return 0;

    unordered_map<int,int> freq;
    for (int x : a) freq[x]++;

    vector<pair<int,int>> items; // {value, count}
    items.reserve(freq.size());
    for (auto &p : freq) items.push_back({p.first, p.second});

    sort(items.begin(), items.end(), [](const pair<int,int>& A, const pair<int,int>& B){
        if (A.second != B.second) return A.second > B.second; // higher freq first
        return A.first < B.first; // smaller value first on tie
    });

    cout << "Top " << k << " frequent elements (value:frequency):\n";
    for (int i = 0; i < (int)items.size() && i < k; ++i) {
        cout << items[i].first << ":" << items[i].second << '\n';
    }

    return 0;
}