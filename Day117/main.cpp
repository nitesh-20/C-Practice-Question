#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int arr[] = {5, 3, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum element: " << findMax(arr, n) << endl;

    return 0;
}
