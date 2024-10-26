// Input all sides of a triangle and check whether the triangle is valid or not.
#include <stdio.h>
int main() {
    float side1, side2, side3;

    // Input sides of the triangle
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%f %f %f", &side1, &side2, &side3);

    // Check if the sum of any two sides is greater than the third side
    if ((side1 + side2 > side3) && 
        (side1 + side3 > side2) && 
        (side2 + side3 > side1)) {
        printf("The triangle is valid.\n");
    } else {
        printf("The triangle is not valid.\n");
    }

    return 0;
}
