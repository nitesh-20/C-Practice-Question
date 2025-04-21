#include <iostream>
using namespace std;

int main() {
    int arr[6] = {5, 8, 11, 2, 9, 4};
    int even = 0, odd = 0;

    for (int i = 0; i < 6; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    cout << "Even: " << even << ", Odd: " << odd << endl;
    return 0;
}
