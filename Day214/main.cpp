#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Edit Distance (Levenshtein Distance) - DP
// Find minimum operations (insert, delete, substitute) to transform s1 to s2

int main() {
    ios::sync_with_stdio(false);

    
    cin.tie(nullptr);

    cout << "Edit Distance (Levenshtein Distance)\n";
    cout << "Enter first string: ";
    string s1;
    if (!getline(cin, s1)) return 0;
    
    cout << "Enter second string: ";
    string s2;
    if (!getline(cin, s2)) return 0;

    int n = s1.length();
    int m = s2.length();
    
    // dp[i][j] = min operations to transform s1[0..i-1] to s2[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    // Base cases
    for (int i = 0; i <= n; ++i) dp[i][0] = i; // delete all
    for (int j = 0; j <= m; ++j) dp[0][j] = j; // insert all
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // no operation needed
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],     // delete from s1
                    dp[i][j-1],     // insert into s1
                    dp[i-1][j-1]    // substitute
                });
            }
        }
    }
    
    cout << "Minimum edit distance: " << dp[n][m] << "\n";
    
    // Reconstruct operations
    cout << "Operations sequence:\n";
    int i = n, j = m;
    vector<string> operations;
    
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && s1[i-1] == s2[j-1]) {
            i--; j--;
            continue;
        }
        
        if (i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1] + 1) {
            operations.push_back("Substitute '" + string(1, s1[i-1]) + "' with '" + string(1, s2[j-1]) + "' at position " + to_string(i-1));
            i--; j--;
        } else if (i > 0 && dp[i][j] == dp[i-1][j] + 1) {
            operations.push_back("Delete '" + string(1, s1[i-1]) + "' at position " + to_string(i-1));
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j-1] + 1) {
            operations.push_back("Insert '" + string(1, s2[j-1]) + "' at position " + to_string(i));
            j--;
        }
    }
    
    reverse(operations.begin(), operations.end());
    for (const string& op : operations) {
        cout << op << "\n";
    }
    
    return 0;
}