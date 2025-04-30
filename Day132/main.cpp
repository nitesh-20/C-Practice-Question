//  Count Number of Digits
#include <iostream>
using namespace std;

int main() {
    int num, count = 0;
    cout << "Enter a number: ";
    cin >> num;

    int temp = num;
    while (temp != 0) {
        temp = temp / 10;
        count++;
    }

    cout << "Number of digits in " << num << " is: " << count << endl;
    return 0;
}
