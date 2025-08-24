#include <iostream>
using namespace std;

unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= n; ++i) result *= i;
    return result;
}

int main() {
    cout << "Enter a non-negative integer: ";
    long long x;
    if (!(cin >> x)) return 0;
    if (x < 0) {
        cout << "Please enter a non-negative integer.\n";
        return 0;
    }
    unsigned long long fact = factorial((unsigned int)x);
    cout << x << "! = " << fact << '\n';
    return 0;
}