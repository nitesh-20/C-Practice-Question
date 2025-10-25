#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Prime Factorization
// Reads an integer n (>1) and prints its prime factors with exponents

int main() {
    cout << "Prime Factorization\n";
    cout << "Enter an integer (>=2): ";
    long long n;
    if (!(cin >> n) || n < 2) {
        cout << "Please enter an integer >= 2\n";
        return 0;
    }

    long long original = n;
    vector<pair<long long,int>> factors;

    for (long long p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                ++cnt;
            }
            factors.push_back({p, cnt});
        }
    }
    if (n > 1) factors.push_back({n, 1});

    cout << "Prime factors of " << original << ":\n";
    for (auto &pr : factors) {
        cout << pr.first << "^" << pr.second << " ";
    }
    cout << '\n';
    return 0;
}