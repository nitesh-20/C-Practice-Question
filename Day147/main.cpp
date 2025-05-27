#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, rev;
    cout << "Enter a string: ";
    cin >> str;

    rev = string(str.rbegin(), str.rend()); // reverse the string

    if (str == rev)
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}
