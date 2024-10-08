#include<stdio.h>
#define PI 3.14159

int main(){
    float radius, area;
    printf("Enter The radius of circle: ");
    scanf("%f",&radius);
    area = PI * radius * radius;
    printf("The area of circle is: %.2f\n",area);
    return 0;
}