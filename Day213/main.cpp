#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Coin Change Problem (DP) - Find minimum coins to make amount
// Also reconstructs which coins are used

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Coin Change Problem (Minimum Coins)\n";
    cout << "Enter number of coin types: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> coins(n);
    cout << "Enter " << n << " coin values:\n";
    for (int i = 0; i < n; ++i) {
        
        cin >> coins[i];
        if (coins[i] <= 0) {
            cout << "Invalid coin value: " << coins[i] << "\n";
            return 0;
        }
    }

    cout << "Enter target amount: ";
    int amount;
    if (!(cin >> amount) || amount < 0) return 0;

    if (amount == 0) {
        cout << "Amount is 0, need 0 coins.\n";
        return 0;
    }

    vector<int> dp(amount + 1, INT_MAX);
    vector<int> parent(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    parent[i] = j; // which coin was used
                }
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        cout << "Cannot make amount " << amount << " with given coins.\n";
    } else {
        cout << "Minimum coins needed: " << dp[amount] << "\n";
        
        // Reconstruct solution
        cout << "Coins used: ";
        vector<int> usedCoins;
        int curr = amount;
        while (curr > 0) {
            int coinIdx = parent[curr];
            usedCoins.push_back(coins[coinIdx]);
            curr -= coins[coinIdx];
        }
        
        for (int coin : usedCoins) cout << coin << " ";
        cout << "\n";
    }

    return 0;
}