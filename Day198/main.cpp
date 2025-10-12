#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Find the first non-repeating character in a string
// Returns the character or prints a message if none found

int main() {
    cout << "First Non-Repeating Character Finder\n";
    cout << "Enter a string: ";
    string s;
    if (!getline(cin, s) || s.empty()) {
        cout << "No input provided. Exiting.\n";
        return 0;
    }

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    char result = '\0';
    for (char c : s) {
        if (freq[c] == 1) { result = c; break; }
    }

    if (result != '\0') cout << "First non-repeating character: '" << result << "'\n";
    else cout << "No non-repeating character found.\n";

    return 0;
}