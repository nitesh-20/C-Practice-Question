#include <iostream>
using namespace std;

// Leap Year Checker Program
bool isLeapYear(int year) {
    // A year is a leap year if:
    // 1. It's divisible by 4 AND
    // 2. If it's divisible by 100, it must also be divisible by 400
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

int main() {
    cout << "Leap Year Checker\n";
    cout << "Enter a year: ";
    int year;
    if (!(cin >> year)) {
        cout << "Invalid input!\n";
        return 0;
    }
    
    if (isLeapYear(year)) {
        cout << year << " is a leap year.\n";
    } else {
        cout << year << " is not a leap year.\n";
    }
    
    // Show some examples
    cout << "\nExamples:\n";
    int examples[] = {2000, 1900, 2004, 2024, 2023};
    for (int ex : examples) {
        cout << ex << ": " << (isLeapYear(ex) ? "Leap" : "Not Leap") << "\n";
    }
    
    return 0;
}