#include <iostream>
#include <tuple>
#include <cstdint>
#include <optional>
#include <cstdlib>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    a = llabs(a); b = llabs(b);
    while (b != 0) {
        int64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int64_t lcm(int64_t a, int64_t b) {
    if (a == 0 || b == 0) return 0;
    return llabs(a / gcd(a, b) * b);
}

// extended gcd: returns (g, x, y) such that a*x + b*y = g = gcd(a,b)
tuple<int64_t,int64_t,int64_t> extended_gcd(int64_t a, int64_t b) {
    if (b == 0) return {llabs(a), (a>=0?1:-1), 0};
    int64_t x0 = 1, y0 = 0;
    int64_t x1 = 0, y1 = 1;
    while (b != 0) {
        int64_t q = a / b;
        int64_t r = a % b;
        int64_t x2 = x0 - q * x1;
        int64_t y2 = y0 - q * y1;
        a = b; b = r;
        x0 = x1; y0 = y1;
        x1 = x2; y1 = y2;
    }
    return {llabs(a), x0, y0};
}

// modular inverse of a modulo m (returns optional<int64_t>)
optional<int64_t> modInverse(int64_t a, int64_t m) {
    auto [g, x, y] = extended_gcd(a, m);
    if (g != 1) return nullopt;
    int64_t inv = x % m;
    if (inv < 0) inv += m;
    return inv;
}

int main() {
    cout << "Number Theory Utilities - GCD, LCM, Extended GCD, Modular Inverse\n";
    cout << "Enter two integers a and b: ";
    int64_t a, b;
    if (!(cin >> a >> b)) return 0;

    int64_t g = gcd(a, b);
    cout << "gcd(" << a << ", " << b << ") = " << g << "\n";

    int64_t L = lcm(a, b);
    cout << "lcm(" << a << ", " << b << ") = " << L << "\n";

    auto [g2, x, y] = extended_gcd(a, b);
    cout << "Extended GCD: " << g2 << " = " << a << "*(" << x << ") + " << b << "*(" << y << ")\n";

    cout << "\nCompute modular inverse of a mod |b| if gcd(a,b)==1" << "\n";
    int64_t mod = llabs(b);
    if (mod == 0) cout << "Cannot compute inverse modulo 0.\n";
    else {
        auto inv = modInverse(a, mod);
        if (inv.has_value()) cout << "Inverse of " << a << " modulo " << mod << " is " << inv.value() << "\n";
        else cout << "Inverse does not exist since gcd(a, mod) != 1\n";
    }

    return 0;
}