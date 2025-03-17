#include <iostream>
#include <cstring>

using namespace std;

struct student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct student student1;
    struct student *ptr = &student1;

    strcpy(ptr->name, "karsh");
    ptr->age = 20;
    ptr->marks = 85.5;

    cout << "Student Details\n";
    cout << "Name: " << ptr->name << endl;
    cout << "Age: " << ptr->age << endl;
    cout << "Marks: " << ptr->marks << endl;

    return 0;
}
