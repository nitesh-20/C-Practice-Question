// Find the Radius, Circumference and Volume of the Cylinder
#include <stdio.h>
#define PI 3.14159

int main() {
    int choice;
    float radius, height, result;

    printf("Choose an option:\n");
    printf("1. Find Radius\n");
    printf("2. Find Circumference\n");
    printf("3. Find Volume\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the circumference of the cylinder: ");
            scanf("%f", &result);
            radius = result / (2 * PI);
            printf("The radius of the cylinder is: %.2f\n", radius);
            break;

        case 2:
            printf("Enter the radius of the cylinder: ");
            scanf("%f", &radius);
            result = 2 * PI * radius;
            printf("The circumference of the cylinder is: %.2f\n", result);
            break;

        case 3:
            printf("Enter the radius of the cylinder: ");
            scanf("%f", &radius);
            printf("Enter the height of the cylinder: ");
            scanf("%f", &height);
            result = PI * radius * radius * height;
            printf("The volume of the cylinder is: %.2f\n", result);
            break;

        default:
            printf("Invalid choice. Please choose 1, 2, or 3.\n");
    }

    return 0;
}
