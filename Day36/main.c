// Input the angles of a triangle and check whether the triangle is valid or not.
#include <stdio.h>
int main() {
    int angle1, angle2, angle3;

    printf("Enter the three angles of the triangle: ");
    scanf("%d %d %d", &angle1, &angle2, &angle3);

    // Check if the sum of the angles is 180 and each angle is greater than 0
    if (angle1 > 0 && angle2 > 0 && angle3 > 0 && (angle1 + angle2 + angle3) == 180) {
        printf("The triangle is valid.\n");
    } else {
        printf("The triangle is not valid.\n");
    }

    return 0;
}
