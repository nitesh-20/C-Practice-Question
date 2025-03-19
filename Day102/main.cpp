// Student Record Management
// Write a C program to create a structure ⁠ Student ⁠ with members ⁠ roll ⁠, ⁠ name ⁠, and ⁠ marks ⁠. Use a pointer to dynamically allocate memory for a single student, prompt the user to input the student’s details (roll number, name, and marks), and then display the details in a formatted manner.

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

int main() {
    Student* s = new Student;
    
    cout << "Enter roll number: ";
    cin >> s->roll;
    
    cout << "Enter name: ";
    cin >> s->name;
    
    cout << "Enter marks: ";
    cin >> s->marks;
    
    cout << "\nStudent Details:\n";
    cout << "Roll Number: " << s->roll << endl;
    cout << "Name: " << s->name << endl;
    cout << "Marks: " << s->marks << endl;
    
    return 0;
}