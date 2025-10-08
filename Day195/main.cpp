#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// Student Grade Management System (Medium Level)
struct Student {
    int id;
    string name;
    vector<double> grades;
    
    double getAverage() const {
        if (grades.empty()) return 0.0;
        double sum = 0;
        for (double grade : grades) sum += grade;
        return sum / grades.size();
    }
    
    char getLetterGrade() const {
        double avg = getAverage();
        if (avg >= 90) return 'A';
        else if (avg >= 80) return 'B';
        else if (avg >= 70) return 'C';
        else if (avg >= 60) return 'D';
        else return 'F';
    }
};

class GradeManager {
    vector<Student> students;
    int nextId = 1;
    
public:
    void addStudent() {
        Student s;
        s.id = nextId++;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, s.name);
        
        cout << "Enter number of grades: ";
        int numGrades;
        cin >> numGrades;
        
        cout << "Enter " << numGrades << " grades: ";
        for (int i = 0; i < numGrades; ++i) {
            double grade;
            cin >> grade;
            s.grades.push_back(grade);
        }
        
        students.push_back(s);
        cout << "Student added successfully with ID: " << s.id << "\n";
    }
    
    void displayAllStudents() {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }
        
        cout << "\n" << setw(5) << "ID" << setw(15) << "Name" 
             << setw(10) << "Average" << setw(8) << "Grade" << "\n";
        cout << "----------------------------------------\n";
        
        for (const auto& s : students) {
            cout << setw(5) << s.id << setw(15) << s.name 
                 << setw(10) << fixed << setprecision(2) << s.getAverage()
                 << setw(8) << s.getLetterGrade() << "\n";
        }
    }
    
    void findStudent() {
        int id;
        cout << "Enter student ID: ";
        cin >> id;
        
        auto it = find_if(students.begin(), students.end(),
                         [id](const Student& s) { return s.id == id; });
        
        if (it != students.end()) {
            cout << "Student found:\n";
            cout << "ID: " << it->id << ", Name: " << it->name << "\n";
            cout << "Grades: ";
            for (double grade : it->grades) cout << grade << " ";
            cout << "\nAverage: " << fixed << setprecision(2) << it->getAverage();
            cout << ", Letter Grade: " << it->getLetterGrade() << "\n";
        } else {
            cout << "Student not found.\n";
        }
    }
    
    void removeStudent() {
        int id;
        cout << "Enter student ID to remove: ";
        cin >> id;
        
        auto it = find_if(students.begin(), students.end(),
                         [id](const Student& s) { return s.id == id; });
        
        if (it != students.end()) {
            cout << "Removed student: " << it->name << "\n";
            students.erase(it);
        } else {
            cout << "Student not found.\n";
        }
    }
    
    void showMenu() {
        cout << "\nStudent Grade Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Find Student\n";
        cout << "4. Remove Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
    }
    
    void run() {
        int choice;
        while (true) {
            showMenu();
            if (!(cin >> choice)) break;
            
            switch (choice) {
                case 1: addStudent(); break;
                case 2: displayAllStudents(); break;
                case 3: findStudent(); break;
                case 4: removeStudent(); break;
                case 5: cout << "Goodbye!\n"; return;
                default: cout << "Invalid choice!\n";
            }
        }
    }
};

int main() {
    GradeManager manager;
    manager.run();
    return 0;
}