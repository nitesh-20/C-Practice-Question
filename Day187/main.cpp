#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    cout << "Easy Array Stats Program\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    vector<long long> a(n);
    cout << "Enter " << n << " integers separated by space:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long sum = 0;
    long long mx = numeric_limits<long long>::min();
    long long mn = numeric_limits<long long>::max();
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (a[i] > mx) mx = a[i];
        if (a[i] < mn) mn = a[i];
    }

    double avg = static_cast<double>(sum) / n;

    cout << "Sum: " << sum << '\n';
    cout << "Average: " << avg << '\n';
    cout << "Maximum: " << mx << '\n';
    cout << "Minimum: " << mn << '\n';

    return 0;
}
