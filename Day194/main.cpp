#include <iostream>
#include <iomanip>
using namespace std;

// Temperature Converter Program
void displayMenu() {
    cout << "\nTemperature Converter\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Celsius to Kelvin\n";
    cout << "4. Kelvin to Celsius\n";
    cout << "5. Fahrenheit to Kelvin\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double temp, result;
    
    cout << fixed << setprecision(2);  // Display 2 decimal places
    
    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }
        
        if (choice == 7) {
            cout << "Thank you for using the temperature converter!\n";
            break;
        }
        
        if (choice >= 1 && choice <= 6) {
            cout << "Enter temperature: ";
            if (!(cin >> temp)) {
                cout << "Invalid temperature!\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            
            switch (choice) {
                case 1:  // Celsius to Fahrenheit
                    result = (temp * 9.0/5.0) + 32;
                    cout << temp << "°C = " << result << "°F\n";
                    break;
                case 2:  // Fahrenheit to Celsius
                    result = (temp - 32) * 5.0/9.0;
                    cout << temp << "°F = " << result << "°C\n";
                    break;
                case 3:  // Celsius to Kelvin
                    result = temp + 273.15;
                    cout << temp << "°C = " << result << "K\n";
                    break;
                case 4:  // Kelvin to Celsius
                    result = temp - 273.15;
                    cout << temp << "K = " << result << "°C\n";
                    break;
                case 5:  // Fahrenheit to Kelvin
                    result = (temp - 32) * 5.0/9.0 + 273.15;
                    cout << temp << "°F = " << result << "K\n";
                    break;
                case 6:  // Kelvin to Fahrenheit
                    result = (temp - 273.15) * 9.0/5.0 + 32;
                    cout << temp << "K = " << result << "°F\n";
                    break;
            }
        } else {
            cout << "Invalid choice! Please select 1-7.\n";
        }
    }
    
    return 0;
}