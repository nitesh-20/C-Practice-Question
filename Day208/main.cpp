#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Longest Common Subsequence (LCS)\n";
    cout << "Enter first string (may contain spaces):\n";
    string A;
    if (!std::getline(cin, A)) return 0;
    if (A.size() == 0) { // if first getline reads empty because of prior newline
        if (!std::getline(cin, A)) return 0;
    }
    cout << "Enter second string (may contain spaces):\n";
    string B;
    if (!std::getline(cin, B)) return 0;

    int n = (int)A.size();
    int m = (int)B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int len = dp[n][m];
    string lcs;
    lcs.reserve(len);
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            lcs.push_back(A[i-1]);
            --i; --j;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());

    cout << "LCS length: " << len << "\n";
    cout << "One LCS: \"" << lcs << "\"\n";
    return 0;
}