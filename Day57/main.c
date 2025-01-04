// Temperature Conversion Celsius To Fahrenheit And Vice Versa
#include <stdio.h>

int main() {
    int choice;
    float temperature, convertedTemperature;

    printf("Temperature Conversion\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            convertedTemperature = (temperature * 9/5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, convertedTemperature);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            convertedTemperature = (temperature - 32) * 5/9;
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, convertedTemperature);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
