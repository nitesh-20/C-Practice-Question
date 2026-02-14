// DSA utility template: sorting, binary search, two-sum
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

// Returns indices (i,j) of a pair summing to target in original array order, or empty vector
vector<int> two_sum_indices(const vector<int>& a, int target) {
	unordered_map<int,int> mp; // value -> index
	for (int i = 0; i < (int)a.size(); ++i) {
		int need = target - a[i];
		if (mp.count(need)) return {mp[need], i};
		mp[a[i]] = i;
	}
	return {};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "DSA helper program\n";
	cout << "Input: n then n integers\n";
	int n;
	if (!(cin >> n)) return 0;
	vector<int> orig(n);
	for (int i = 0; i < n; ++i) cin >> orig[i];

	// Sorting
	vector<int> a = orig;
	sort(a.begin(), a.end());
	cout << "Sorted array:\n";
	for (int x : a) cout << x << ' ';
	cout << '\n';

	// Binary search demo
	cout << "Enter value to binary-search: \n";
	int qv; cin >> qv;
	int pos = binary_search_idx(a, qv);
	if (pos != -1) cout << "Found at sorted index: " << pos << '\n';
	else cout << "Not found\n";

	// Two-sum demo on original array
	cout << "Enter target for two-sum: \n";
	int target; cin >> target;
	auto res = two_sum_indices(orig, target);
	if (!res.empty()) cout << "Pair indices in original array: " << res[0] << ' ' << res[1] << '\n';
	else cout << "No pair found\n";

	return 0;
}

