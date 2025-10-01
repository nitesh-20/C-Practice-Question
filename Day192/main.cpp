#include <iostream>
using namespace std;

// Simple Calculator Program
void displayMenu() {
    cout << "\nSimple Calculator\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double num1, num2, result;
    
    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }
        
        if (choice == 5) {
            cout << "Thank you for using the calculator!\n";
            break;
        }
        
        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            
            switch (choice) {
                case 1:
                    result = num1 + num2;
                    cout << num1 << " + " << num2 << " = " << result << "\n";
                    break;
                case 2:
                    result = num1 - num2;
                    cout << num1 << " - " << num2 << " = " << result << "\n";
                    break;
                case 3:
                    result = num1 * num2;
                    cout << num1 << " * " << num2 << " = " << result << "\n";
                    break;
                case 4:
                    if (num2 != 0) {
                        result = num1 / num2;
                        cout << num1 << " / " << num2 << " = " << result << "\n";
                    } else {
                        cout << "Error: Division by zero!\n";
                    }
                    break;
            }
        } else {
            cout << "Invalid choice! Please select 1-5.\n";
        }
    }
    
    return 0;
}