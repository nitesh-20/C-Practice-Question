#include <iostream>
using namespace std;

int main() {
    int num, i, flag = 0;
    cout << "Enter a number: ";
    cin >> num;

    if (num <= 1) {
        cout << "Not a prime number." << endl;
        return 0;
    }

    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}
