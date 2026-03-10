// Simple C++ utility: read integers, print stats and sorted list
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstddef>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "Enter count of numbers (n): ";
	long long n;
	if (!(cin >> n) || n <= 0) {
		cerr << "Invalid count. Please enter a positive integer.\n";
		return 1;
	}

	vector<long long> a;
	a.reserve((size_t)n);
	cout << "Enter " << n << " integer(s), separated by spaces or newlines:\n";
	for (long long i = 0; i < n; ++i) {
		long long x;
		if (!(cin >> x)) {
			cerr << "Failed to read number #" << (i+1) << "\n";
			return 1;
		}
		a.push_back(x);
	}

	long long sum = 0;
	for (auto v : a) sum += v;
	auto minmax = minmax_element(a.begin(), a.end());
	sort(a.begin(), a.end());

	cout << "\nResults:\n";
	cout << "Count: " << n << '\n';
	cout << "Sum: " << sum << '\n';
	cout << fixed << setprecision(4);
	cout << "Average: " << (double)sum / (double)n << '\n';
	cout << "Min: " << *minmax.first << '\n';
	cout << "Max: " << *minmax.second << '\n';

	cout << "Sorted list: ";
	for (size_t i = 0; i < a.size(); ++i) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << '\n';

	return 0;
}

