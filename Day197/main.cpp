#include <iostream>
using namespace std;

// Pattern Printing Program (Easy)
void printTriangle1(int n) {
    cout << "\nPattern 1 - Right Triangle:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

void printTriangle2(int n) {
    cout << "\nPattern 2 - Inverted Triangle:\n";
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}

void printTriangle3(int n) {
    cout << "\nPattern 3 - Number Triangle:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void printTriangle4(int n) {
    cout << "\nPattern 4 - Pyramid:\n";
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

void printTriangle5(int n) {
    cout << "\nPattern 5 - Diamond:\n";
    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << "\n";
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << "\n";
    }
}

int main() {
    cout << "Pattern Printing Program\n";
    cout << "Enter the size of pattern: ";
    int n;
    
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid input! Please enter a positive number.\n";
        return 0;
    }
    
    printTriangle1(n);
    printTriangle2(n);
    printTriangle3(n);
    printTriangle4(n);
    printTriangle5(n);
    
    return 0;
}