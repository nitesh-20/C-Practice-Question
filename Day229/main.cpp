#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Quickselect algorithm to find the k-th smallest element in an unsorted array.
// Average Time: O(n), Worst-case: O(n^2) (rare if we randomize pivot).

int partition(std::vector<int> &arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]); // move pivot to end
    int storeIndex = left;

    for (int i = left; i < right; ++i) {
        if (arr[i] < pivotValue) {
            std::swap(arr[storeIndex], arr[i]);
            ++storeIndex;
        }
    }
    std::swap(arr[storeIndex], arr[right]); // move pivot to its final place
    return storeIndex;
}

int quickselect(std::vector<int> &arr, int left, int right, int k) {
    // k is 0-based index: k = 0 => smallest, k = 1 => 2nd smallest, etc.
    while (true) {
        if (left == right) return arr[left];

        int pivotIndex = left + std::rand() % (right - left + 1);
        pivotIndex = partition(arr, left, right, pivotIndex);

        if (k == pivotIndex) {
            return arr[k];
        } else if (k < pivotIndex) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex + 1;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "===== Quickselect: k-th Smallest Element Demo =====\n";

    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid size. Exiting.\n";
        return 0;
    }

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int k;
    std::cout << "Enter k (1-based) to find k-th smallest: ";
    std::cin >> k;

    if (k < 1 || k > n) {
        std::cout << "k must be between 1 and " << n << ". Exiting.\n";
        return 0;
    }

    // Convert to 0-based index
    int kIndex = k - 1;

    std::vector<int> copy = arr; // keep original array for display
    int kth = quickselect(copy, 0, n - 1, kIndex);

    std::cout << k << "-th smallest element is: " << kth << "\n";

    std::cout << "(Original array remains unchanged except for this copy.)\n";

    return 0;
}
