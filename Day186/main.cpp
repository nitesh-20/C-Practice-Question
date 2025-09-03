#include <iostream>
#include <vector>
using namespace std;


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
       
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
       
        if (minIndex != i) swap(arr[i], arr[minIndex]);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << ' ';
    cout << '\n';
}

int main() {
    cout << "Selection Sort Demo\n";
    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> arr(n);
    cout << "Enter " << n << " elements separated by space:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "Original array: "; printArray(arr);
    selectionSort(arr);
    cout << "Sorted array:   "; printArray(arr);

    return 0;
}