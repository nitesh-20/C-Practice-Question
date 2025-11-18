#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Sliding Window Maximum - find max in all subarrays of size k
// Uses deque to maintain indices in decreasing order of values

vector<int> slidingWindowMaximum(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    deque<int> dq; // stores indices
    
    for (int i = 0; i < n; ++i) {
        // Remove indices outside current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove indices whose values are smaller than current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Window is complete when i >= k-1
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Sliding Window Maximum\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "Enter window size k: ";
    int k;
    if (!(cin >> k) || k <= 0 || k > n) {
        cout << "Invalid window size\n";
        return 0;
    }

    vector<int> maxValues = slidingWindowMaximum(arr, k);

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "Maximum in each window of size " << k << ":\n";
    for (int i = 0; i < (int)maxValues.size(); ++i) {
        cout << "Window [" << i << "," << (i + k - 1) << "]: " << maxValues[i] << "\n";
    }

    return 0;
}