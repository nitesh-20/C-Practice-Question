#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Medium level DSA: Coin Change (Minimum Coins)
// Given coin denominations and an amount, find the minimum number of coins
// needed to make that amount, and print one optimal combination.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== Coin Change (Minimum Coins) DP Demo =====\n";

    int n;
    cout << "Enter number of coin types: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n. Exiting.\n";
        return 0;
    }

    vector<int> coins(n);
    cout << "Enter " << n << " coin denominations: ";
    for (int i = 0; i < n; ++i) cin >> coins[i];

    int amount;
    cout << "Enter amount to make: ";
    cin >> amount;
    if (amount < 0) {
        cout << "Amount cannot be negative. Exiting.\n";
        return 0;
    }

    const int INF = numeric_limits<int>::max() / 2;
    vector<int> dp(amount + 1, INF);
    vector<int> parent(amount + 1, -1); // parent[x] = index of coin used to reach x

    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int c = coins[i];
        if (c <= 0) continue; // ignore non-positive coins
        for (int x = c; x <= amount; ++x) {
            if (dp[x - c] + 1 < dp[x]) {
                dp[x] = dp[x - c] + 1;
                parent[x] = i;
            }
        }
    }

    if (dp[amount] >= INF) {
        cout << "It is not possible to make amount " << amount << " with given coins.\n";
        return 0;
    }

    cout << "Minimum number of coins needed: " << dp[amount] << "\n";

    // Reconstruct one optimal combination
    cout << "One optimal combination of coins: ";
    int cur = amount;
    bool first = true;
    while (cur > 0) {
        int idx = parent[cur];
        if (idx == -1) break; // should not happen if dp[amount] is valid
        if (!first) cout << ", ";
        first = false;
        cout << coins[idx];
        cur -= coins[idx];
    }
    cout << "\n";

    return 0;
}
