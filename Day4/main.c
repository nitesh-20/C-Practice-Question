#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    /* Input temperature in Celsius */
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    /* Celsius to Fahrenheit conversion formula */
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    /* Display the result */
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}
