#include <iostream>
using namespace std;

int main() {
    int num, count = 0;
    cout << "Enter a number: ";
    cin >> num;

    if (num == 0) count = 1; 

    while (num != 0) {
        num /= 10;     
        count++;       
    }

    cout << "Total digits: " << count << endl;

    return 0;
}
