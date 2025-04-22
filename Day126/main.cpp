#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 2, 1};
    bool isPalindrome = true;

    for (int i = 0; i < 5 / 2; i++) {
        if (arr[i] != arr[4 - i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "Array is a palindrome.\n";
    else
        cout << "Array is not a palindrome.\n";

    return 0;
}
