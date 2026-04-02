#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    // TODO: Implement your logic here
    // Hint: Consider using a sliding window approach
    
    return 0;
}

int main() {
    string s1 = "abcabcbb";
    
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    
    cout << "Input: " << s1 << " | Output: " << lengthOfLongestSubstring(s1) << " (Expected: 3)" << endl;
    cout << "Input: " << s2 << " | Output: " << lengthOfLongestSubstring(s2) << " (Expected: 1)" << endl;
    cout << "Input: " << s3 << " | Output: " << lengthOfLongestSubstring(s3) << " (Expected: 3)" << endl;
    
    return 0;
}
