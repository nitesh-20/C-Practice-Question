#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int marks[5];
    float average;
    char grade;

    public:
    void getData(){
        cout << "Enter Student Name: ";
        getline(cin,name);

        cout << "Enter marks for 5 subjects (out of 100):"<< endl;
        int total = 0;
        for(int i =0; i<5; i++){
            cout<< "Subject " << i+1 << ": ";
            cin >> marks[i];
            total += marks[i];
        }
        average = total / 5.0;

        if(average >= 90) {
            grade = 'A';
        } else if (average >= 80) {
            grade = 'B';
        } else if (average >= 70) {
            grade = 'C';
        } else if (average >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }
    void displayData(){
        cout << "Student Name: " << name << endl;
        cout << "Average Marks: " << average << endl;
        cout << "Grade: " << grade << endl;
    }
};
int main(){
    Student s;
    s.getData();
    s.displayData();
    return 0;
}