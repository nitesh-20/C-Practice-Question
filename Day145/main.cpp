#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
        cout << "Factorial of a negative number doesn't exist." << endl;
    else {
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
        cout << "Factorial of " << n << " = " << fact << endl;
    }

    return 0;
}