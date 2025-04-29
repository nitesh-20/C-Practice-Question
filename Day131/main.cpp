#include <iostream>
using namespace std;

int main() {
    int arr[5] = {3, 7, 1, 9, 5};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }

    cout << "Sum of array elements: " << sum << endl;

    return 0;
}
