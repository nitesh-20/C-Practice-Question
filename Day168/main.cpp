#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter value of N (range from 1 to N): ";
    cin >> n;

    int sum = n * (n + 1) / 2;
    int actualSum = 0;

    cout << "Enter " << n - 1 << " elements: ";
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        actualSum += x;
    }

    cout << "Missing number is: " << sum - actualSum;
    return 0;
}
