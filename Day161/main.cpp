#include <iostream>
using namespace std;

int main() {
    int n, key, found = 0;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i;
            found = 1;
            break;
        }
    }

    if (!found)
        cout << "Element not found.";
    return 0;
}
