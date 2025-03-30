#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    cout << "Enter any number: ";
    cin >> n;

    for (int i = 2; i <= n; i+=2) {
        sum += i;
    }

    cout << "The sum of " << n << " even numbers is: " << sum << endl;

    return 0;
}