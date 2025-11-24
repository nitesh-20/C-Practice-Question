#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Matrix Chain Multiplication - DP
// Find minimum scalar multiplications needed to multiply a chain of matrices

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Matrix Chain Multiplication (Minimum Scalar Multiplications)\n";
    cout << "Enter number of matrices: ";
    int n;
    if (!(cin >> n) || n <= 1) {
        cout << "Need at least 2 matrices\n";
        return 0;
    }
    

    vector<int> p(n + 1);
    cout << "Enter " << (n + 1) << " dimensions (p0, p1, ..., p" << n << "):\n";
    cout << "Matrix i has dimensions p[i-1] x p[i]\n";
    for (int i = 0; i <= n; ++i) {
        cin >> p[i];
        if (p[i] <= 0) {
            cout << "Invalid dimension: " << p[i] << "\n";
            return 0;
        }
    }

    // Display matrices
    cout << "Matrices:\n";
    for (int i = 1; i <= n; ++i) {
        cout << "M" << i << ": " << p[i-1] << " x " << p[i] << "\n";
    }

    // dp[i][j] = minimum scalar multiplications for matrices i to j
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

    // l is chain length
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; ++k) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum scalar multiplications needed: " << dp[1][n] << "\n";

    // Reconstruct optimal parenthesization
    function<void(int, int)> printOptimal = [&](int i, int j) {
        if (i == j) {
            cout << "M" << i;
        } else {
            cout << "(";
            printOptimal(i, split[i][j]);
            printOptimal(split[i][j] + 1, j);
            cout << ")";
        }
    };

    cout << "Optimal parenthesization: ";
    printOptimal(1, n);
    cout << "\n";

    return 0;
}