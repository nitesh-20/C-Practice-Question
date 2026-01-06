#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Longest Common Substring (not subsequence) between two strings
// DP solution in O(n * m) time and O(n * m) space.

int main() {
    std::cout << "===== Longest Common Substring Demo =====\n";

    std::string s1, s2;
    std::cout << "Enter first string: ";
    std::getline(std::cin, s1);
    if (s1.empty()) {
        std::cout << "First string is empty. Exiting.\n";
        return 0;
    }

    std::cout << "Enter second string: ";
    std::getline(std::cin, s2);
    if (s2.empty()) {
        std::cout << "Second string is empty. Exiting.\n";
        return 0;
    }

    int n = static_cast<int>(s1.size());
    int m = static_cast<int>(s2.size());

    // dp[i][j] = length of longest common substring ending at s1[i-1], s2[j-1]
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    int bestLen = 0;
    int endPos = 0; // end position in s1 of best substring

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > bestLen) {
                    bestLen = dp[i][j];
                    endPos = i - 1;
                }
            } else {
                dp[i][j] = 0; // substring must be contiguous
            }
        }
    }

    std::cout << "Length of Longest Common Substring: " << bestLen << "\n";

    if (bestLen > 0) {
        std::string lcs = s1.substr(endPos - bestLen + 1, bestLen);
        std::cout << "One Longest Common Substring: " << lcs << "\n";
    } else {
        std::cout << "No common substring found (other than empty string).\n";
    }

    return 0;
}
