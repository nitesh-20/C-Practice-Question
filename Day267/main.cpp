#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string lcs(const string &a, const string &b) {
	int n = (int)a.size(), m = (int)b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string res;
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) { res.push_back(a[i - 1]); --i; --j; }
		else if (dp[i - 1][j] > dp[i][j - 1]) --i;
		else --j;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;
	cout << "Enter first string:\n";
	if (!getline(cin, s)) return 0;
	cout << "Enter second string:\n";
	if (!getline(cin, t)) return 0;

	string res = lcs(s, t);
	cout << "LCS length: " << res.size() << '\n';
	cout << "LCS: " << res << '\n';
	return 0;
}
