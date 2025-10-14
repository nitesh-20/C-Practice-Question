#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Find majority element (> n/2 occurrences) using Boyer-Moore Voting Algorithm
int majorityElement(const vector<int>& a) {
    int count = 0, candidate = 0;
    for (int x : a) {
        if (count == 0) candidate = x;
        count += (x == candidate) ? 1 : -1;
    }
    // verify candidate
    count = 0;
    for (int x : a) if (x == candidate) ++count;
    if (count > (int)a.size() / 2) return candidate;
    return INT_MIN; // indicates no majority element
}

int main() {
    cout << "Majority Element Finder (Boyer-Moore)\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;
    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int maj = majorityElement(arr);
    if (maj == INT_MIN) cout << "No majority element (no element appears more than n/2 times).\n";
    else cout << "Majority element is: " << maj << "\n";
    return 0;
}