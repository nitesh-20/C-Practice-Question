#include <iostream>
using namespace std;

int main() {
    int num, reversed = 0, digit;
    cout << "Enter a number: ";
    cin >> num;

    while (num != 0) {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
    }

    cout << "Reversed number: " << reversed << endl;
    return 0;
}
