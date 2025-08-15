#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum element in an array
int findMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

int main() {
    vector<int> arr = {10, 25, 7, 56, 32};
    cout << "Array elements: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Maximum element: " << findMax(arr) << endl;
    return 0;
}