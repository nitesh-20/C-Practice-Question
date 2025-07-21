#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    cout << "Frequencies:\n";
    for (auto p : freq) {
        cout << p.first << " occurs " << p.second << " times\n";
    }
}
