#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Problem: Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        

        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If the character is already in the map and its index is within the current window
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1;
            }
            
            charIndexMap[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    string testStr1 = "abcabcbb"; // Expected: 3 ("abc")
    string testStr2 = "bbbbb";    // Expected: 1 ("b")
    string testStr3 = "pwwkew";   // Expected: 3 ("wke")

    cout << "Longest substring length for '" << testStr1 << "': " 
         << solution.lengthOfLongestSubstring(testStr1) << endl;
         
    cout << "Longest substring length for '" << testStr2 << "': " 
         << solution.lengthOfLongestSubstring(testStr2) << endl;
         
    cout << "Longest substring length for '" << testStr3 << "': " 
         << solution.lengthOfLongestSubstring(testStr3) << endl;

    return 0;
}
