// Area and Circumference of a Circle
#include <iostream>
using namespace std;

int main(){
    int radius;
    const float PI = 3.14;
    float area , circumeference;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    area = PI * radius * radius;
    circumeference = 2 * PI * radius;

    cout << "Area of the circle: " << area << endl;
    cout << "Circumference of the circle: " <<circumeference << endl;

    return 0;
}