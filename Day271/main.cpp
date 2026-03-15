#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <cmath>
using namespace std;

unsigned long long factorial(unsigned int n) {
	unsigned long long res = 1;
	for (unsigned int i = 2; i <= n; ++i) res *= i;
	return res;
}

bool isPrime(unsigned long long n) {
	if (n < 2) return false;
	if (n % 2 == 0) return n == 2;
	for (unsigned long long i = 3; i * i <= n; i += 2)
		if (n % i == 0) return false;
	return true;
}

unsigned long long fibonacci(unsigned int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	unsigned long long a = 0, b = 1;
	for (unsigned int i = 2; i <= n; ++i) {
		unsigned long long t = a + b;
		a = b; b = t;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		cout << "\nC++ Practice Menu:\n";
		cout << "1) Factorial\n";
		cout << "2) Prime check\n";
		cout << "3) Fibonacci (n-th)\n";
		cout << "4) Sort numbers\n";
		cout << "5) Exit\n";
		cout << "Choose option: ";

		int opt;
		if (!(cin >> opt)) break;

		if (opt == 1) {
			cout << "Enter non-negative integer: ";
			unsigned int n; cin >> n;
			cout << n << "! = " << factorial(n) << "\n";
		} else if (opt == 2) {
			cout << "Enter integer to check prime: ";
			unsigned long long x; cin >> x;
			cout << x << (isPrime(x) ? " is prime\n" : " is not prime\n");
		} else if (opt == 3) {
			cout << "Enter n (0-based): ";
			unsigned int n; cin >> n;
			cout << "Fibonacci(" << n << ") = " << fibonacci(n) << "\n";
		} else if (opt == 4) {
			cout << "How many numbers? ";
			int m; cin >> m;
			if (m <= 0) { cout << "Nothing to sort.\n"; continue; }
			vector<long long> a(m);
			cout << "Enter " << m << " numbers:\n";
			for (int i = 0; i < m; ++i) cin >> a[i];
			sort(a.begin(), a.end());
			cout << "Sorted: ";
			for (auto v : a) cout << v << " ";
			cout << "\n";
		} else if (opt == 5) {
			cout << "Goodbye.\n";
			break;
		} else {
			cout << "Invalid option. Try again.\n";
		}
	}

	return 0;
}
