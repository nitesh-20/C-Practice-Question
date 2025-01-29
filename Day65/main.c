#include <stdio.h>

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } 
        else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } 
        else {
            return i;
        }
    }

    if (fib1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 50, 60, 80, 180};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 80;

    int index = fibonacciSearch(arr, n, x);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}
