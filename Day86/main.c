// Get the second largest element in an array.
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 5, 30, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = arr[0], second_largest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    printf("Second largest element: %d\n", second_largest);
    return 0;
}
