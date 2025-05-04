#include <iostream>
using namespace std;

int main() {
    int num, reversed = 0, original, digit;
    cout << "Enter a number: ";
    cin >> num;

    original = num;

    while (num != 0) {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
    }

    if (original == reversed)
        cout << original << " is a palindrome." << endl;
    else
        cout << original << " is not a palindrome." << endl;

    return 0;
}
