#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes - list primes up to n
// Time complexity: O(n log log n)

int main() {
    cout << "Sieve of Eratosthenes - list primes up to n\n";
    cout << "Enter n (>=2): ";
    int n;
    if (!(cin >> n) || n < 2) {
        cout << "Please enter an integer >= 2\n";
        return 0;
    }

    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p)
                isPrime[multiple] = false;
        }
    }

    cout << "Prime numbers up to " << n << ":\n";
    for (int i = 2; i <= n; ++i) if (isPrime[i]) cout << i << ' ';
    cout << '\n';
    return 0;
}