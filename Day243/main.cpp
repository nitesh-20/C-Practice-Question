#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Longest Palindromic Subsequence (LPS)
// Dynamic Programming: O(n^2) time and O(n^2) space
// Also reconstructs one LPS string.

int main() {
    std::cout << "===== Longest Palindromic Subsequence (LPS) Demo =====\n";

    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    if (s.empty()) {
        std::cout << "Empty string. Exiting.\n";
        return 0;
    }

    int n = static_cast<int>(s.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // dp[i][j] = length of LPS in s[i..j]
    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = (len == 2) ? 2 : dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    int lpsLen = dp[0][n - 1];
    std::cout << "Length of Longest Palindromic Subsequence: " << lpsLen << "\n";

    // Reconstruct one LPS
    std::string leftPart, rightPart;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (s[i] == s[j]) {
            if (i == j) {
                // middle character of odd-length palindrome
                leftPart.push_back(s[i]);
            } else {
                leftPart.push_back(s[i]);
                rightPart.push_back(s[j]);
            }
            ++i;
            --j;
        } else if (dp[i + 1][j] >= dp[i][j - 1]) {
            ++i;
        } else {
            --j;
        }
    }

    std::reverse(rightPart.begin(), rightPart.end());
    std::string lps = leftPart + rightPart;

    std::cout << "One Longest Palindromic Subsequence: " << lps << "\n";

    return 0;
}
