#include <iostream>
#include <string>
using namespace std;

// Simple Palindrome Checker (easy DSA)
bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    cout << "Palindrome Checker\n";
    cout << "Enter a string: ";
    string input;
    if (!getline(cin, input)) return 0;
    
    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome!\n";
    } else {
        cout << "\"" << input << "\" is not a palindrome.\n";
    }
    
    return 0;
}