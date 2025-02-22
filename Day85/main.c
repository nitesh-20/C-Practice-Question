// Find a maximum and minimum element in an array-using recursion.
#include <stdio.h>

void findMaxMin(int arr[], int n, int index, int *max, int *min) {
    if (index == n) {
        return;
    }

    if (arr[index] > *max) {
        *max = arr[index];
    }
    if (arr[index] < *min) {
        *min = arr[index];
    }

    findMaxMin(arr, n, index + 1, max, min);
}
int main() {
    int arr[] = {12, 5, 87, 3, 22, 45, 78};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0], min = arr[0]; 

    findMaxMin(arr, n, 1, &max, &min);

    printf("Maximum Element: %d\n", max);
    printf("Minimum Element: %d\n", min);

    return 0;
}
