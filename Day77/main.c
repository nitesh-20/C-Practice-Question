// Delete Element From Array At Desired Or Specific Position
#include <stdio.h>

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Reduce array size
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int position;

    printf("Original array: ");
    displayArray(arr, size);

    printf("Enter position to delete (0-based index): ");
    scanf("%d", &position);

    deleteElement(arr, &size, position);

    printf("Array after deletion: ");
    displayArray(arr, size);

    return 0;
}
