#include <iostream>
#include <vector>
using namespace std;

// Fibonacci with Memoization (medium level DSA - Dynamic Programming)
vector<long long> memo;

long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}

int main() {
    cout << "Fibonacci with Memoization\n";
    cout << "Enter n: ";
    int n;
    if (!(cin >> n) || n < 0) return 0;
    
    memo.assign(n + 1, -1);
    long long result = fib(n);
    cout << "fib(" << n << ") = " << result << "\n";
    
    cout << "First " << n+1 << " Fibonacci numbers:\n";
    for (int i = 0; i <= n; ++i) {
        cout << fib(i) << " ";
    }
    cout << "\n";
    
    return 0;
}