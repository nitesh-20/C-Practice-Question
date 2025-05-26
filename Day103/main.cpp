// Array of Student Pointers
// Create a structure ⁠ Student ⁠ with members ⁠ roll ⁠ and ⁠ name ⁠. Use an array of pointers to dynamically allocate memory for 3 students. Prompt the user to input the roll number and name for each student, then display the details of all students in reverse order of entry.
#include <iostream>

using namespace std;


struct Student {
    int roll;
    char name[50];
};

int main() {
    int n = 3;
    Student* students[n];

    for (int i = 0; i < n; i++) {
        students[i] = new Student;
        cout << "Enter roll number for student " << i + 1 << ": ";
        cin >> students[i]->roll;
        cout << "Enter name for student " << i + 1 << ": ";
        cin >> students[i]->name;
    }

    cout << "\nStudent Details in Reverse Order:\n";
    for (int i = n - 1; i >= 0; i--) {
        cout << "Roll: " << students[i]->roll << ", Name: " << students[i]->name << endl;
    }

    for (int i = 0; i < n; i++) {
        delete students[i];
    }

    return 0;
}

