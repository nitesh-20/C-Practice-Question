// Read and print elements of the array.– using recursion.
#include <stdio.h>

void readArray(int arr[], int n, int index) {
    if (index == n)  // Base condition
        return;
    
    printf("Enter element at index %d: ", index);
    scanf("%d", &arr[index]);

    readArray(arr, n, index + 1);  // Recursive call
}

void printArray(int arr[], int n, int index) {
    if (index == n)  // Base condition
        return;

    printf("%d ", arr[index]);
    
    
    printArray(arr, n, index + 1);  // Recursive call
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];  // Declaring array
    
    // Reading array elements
    readArray(arr, n, 0);
    
    printf("Array elements are: ");
    // Printing array elements
    printArray(arr, n, 0);
    
    return 0;
}
