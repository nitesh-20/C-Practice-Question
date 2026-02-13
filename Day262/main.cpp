
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Sieve of Eratosthenes: print all primes <= N
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	if (!(cin >> N)) return 0;
	if (N < 2) return 0;

	vector<char> is_prime(N+1, true);
	is_prime[0] = is_prime[1] = false;
	for (long long p = 2; p * p <= N; ++p) {
		if (is_prime[p]) {
			for (long long q = p * p; q <= N; q += p) is_prime[q] = false;
		}
	}

	bool first = true;
	for (long long i = 2; i <= N; ++i) {
		if (is_prime[i]) {
			if (!first) cout << ' ';
			cout << i;
			first = false;
		}
	}
	cout << '\n';
	return 0;
}
