#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// String Reversal Program (Easy)
string reverseString1(string str) {
    // Method 1: Using two pointers
    int left = 0, right = str.length() - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
    return str;
}

string reverseString2(string str) {
    // Method 2: Using built-in reverse function
    reverse(str.begin(), str.end());
    return str;
}

string reverseString3(string str) {
    // Method 3: Using loop and new string
    string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

int main() {
    cout << "String Reversal Program\n";
    cout << "Enter a string: ";
    string input;
    
    // Read the entire line including spaces
    getline(cin, input);
    
    if (input.empty()) {
        cout << "No input provided!\n";
        return 0;
    }
    
    cout << "\nOriginal string: \"" << input << "\"\n";
    cout << "\nReversed using different methods:\n";
    
    cout << "Method 1 (Two pointers): \"" << reverseString1(input) << "\"\n";
    cout << "Method 2 (Built-in reverse): \"" << reverseString2(input) << "\"\n";
    cout << "Method 3 (Loop with new string): \"" << reverseString3(input) << "\"\n";
    
    return 0;
}