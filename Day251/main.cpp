#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Medium level DSA: Longest Substring Without Repeating Characters
// Sliding window + last index array, O(n) time.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== Longest Substring Without Repeating Characters =====\n";

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (s.empty()) {
        cout << "Empty string. Exiting.\n";
        return 0;
    }

    // last position of each ASCII char, -1 = not seen
    vector<int> last(256, -1);
    int bestLen = 0;
    int bestL = 0;
    int left = 0; // current window [left..right]

    for (int right = 0; right < (int)s.size(); ++right) {
        unsigned char ch = s[right];
        if (last[ch] >= left) {
            // character repeated inside current window
            left = last[ch] + 1;
        }
        last[ch] = right;

        int curLen = right - left + 1;
        if (curLen > bestLen) {
            bestLen = curLen;
            bestL = left;
        }
    }

    cout << "Length of longest substring without repeating characters: " << bestLen << "\n";
    cout << "One such substring: " << s.substr(bestL, bestLen) << "\n";

    return 0;
}
