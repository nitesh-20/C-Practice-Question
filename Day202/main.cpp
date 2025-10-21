#include <iostream>
#include <tuple>
#include <cstdlib>
using namespace std;

long long gcd(long long a, long long b) {
    a = llabs(a); b = llabs(b);
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}



long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return llabs(a / gcd(a, b) * b);
}

// extended gcd: returns (g, x, y) such that a*x + b*y = g = gcd(a,b)
tuple<long long,long long,long long> extended_gcd(long long a, long long b) {
    if (b == 0) return {llabs(a), (a>=0?1:-1), 0};
    long long x0 = 1, y0 = 0;
    long long x1 = 0, y1 = 1;
    while (b != 0) {
        long long q = a / b;
        long long r = a % b;
        long long x2 = x0 - q * x1;
        long long y2 = y0 - q * y1;
        a = b; b = r;
        x0 = x1; y0 = y1;
        x1 = x2; y1 = y2;
    }
    return {llabs(a), x0, y0};
}

// modular inverse of a modulo m (returns pair<bool, inv>)
pair<bool,long long> modInverse(long long a, long long m) {
    auto [g, x, y] = extended_gcd(a, m);
    if (g != 1) return {false, 0};
    long long inv = x % m;
    if (inv < 0) inv += m;
    return {true, inv};
}

int main() {
    cout << "Number Theory Utilities - GCD, LCM, Extended GCD, Modular Inverse\n";
    cout << "Enter two integers a and b: ";
    long long a, b;
    if (!(cin >> a >> b)) return 0;

    long long g = gcd(a, b);
    cout << "gcd(" << a << ", " << b << ") = " << g << "\n";

    long long L = lcm(a, b);
    cout << "lcm(" << a << ", " << b << ") = " << L << "\n";

    auto [g2, x, y] = extended_gcd(a, b);
    cout << "Extended GCD: " << g2 << " = " << a << "*(" << x << ") + " << b << "*(" << y << ")\n";

    cout << "\nCompute modular inverse of a mod |b| if gcd(a,b)==1" << "\n";
    long long mod = llabs(b);
    if (mod == 0) cout << "Cannot compute inverse modulo 0.\n";
    else {
        auto [ok, inv] = modInverse(a, mod);
        if (ok) cout << "Inverse of " << a << " modulo " << mod << " is " << inv << "\n";
        else cout << "Inverse does not exist since gcd(a, mod) != 1\n";
    }

    return 0;
}