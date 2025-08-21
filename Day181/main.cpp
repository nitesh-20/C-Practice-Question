#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    cout << "Enter a number: ";
    long long x;
    if (!(cin >> x)) return 0;
    if (isPrime(x)) cout << x << " is a prime number\n";
    else cout << x << " is not a prime number\n";
    return 0;
}
