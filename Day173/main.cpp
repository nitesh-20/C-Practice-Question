#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n (total count): ";
    cin >> n;
    int arr[n - 1];

    cout << "Enter " << n - 1 << " elements: ";
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int expectedSum = n * (n + 1) / 2;
    cout << "Missing number is: " << expectedSum - sum << endl;
}
