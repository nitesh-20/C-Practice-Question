#include <iostream>
#include <vector>
using namespace std;

// Generate all subsets (power set) of an array using backtracking

void backtrack(int idx, const vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (idx == (int)nums.size()) {
        result.push_back(current);
        return;
    }
    // Choice 1: exclude nums[idx]
    backtrack(idx + 1, nums, current, result);
    // Choice 2: include nums[idx]
    current.push_back(nums[idx]);
    backtrack(idx + 1, nums, current, result);
    current.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    
    cin.tie(nullptr);

    cout << "Subsets (Power Set) Generator\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n < 0) return 0;

    vector<int> nums(n);
    if (n > 0) {
        cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; ++i) cin >> nums[i];
    }

    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);

    cout << "\nAll subsets (" << result.size() << " total):\n";
    for (const auto& subset : result) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ", ";
        }
        cout << "}\n";
    }

    return 0;
}