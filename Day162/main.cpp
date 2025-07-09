#include <iostream>
using namespace std;

int main() {
    int n, count;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], freq[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        count = 1;
        if (freq[i] != 0) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; // Mark as counted
                }
            }
            freq[i] = count;
        }
    }

    cout << "\nElement | Frequency\n";
    for (int i = 0; i < n; i++) {
        if (freq[i] != 0)
            cout << "   " << arr[i] << "    |    " << freq[i] << endl;
    }

    return 0;
}
