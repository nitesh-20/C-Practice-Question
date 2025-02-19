// Print all negative elements in an array.
#include <stdio.h>

int main() {
    int n, i;
    
    // Input: Number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input: Array elements
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Output: Negative elements
    printf("Negative elements in the array: ");
    for(i = 0; i < n; i++) {
        if(arr[i] < 0) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
