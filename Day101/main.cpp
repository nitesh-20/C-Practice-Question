#include <iostream>
using namespace std;

struct Branch {
    string name;
};

struct HodDetails {
    string name;
    int age;
    float salary;
};

int main() {
    int n = 3;
    Branch* branches = new Branch[n];
    HodDetails* hods = new HodDetails[n];

    string branchNames[] = {"CSE", "ME", "EE"};
    string hodNames[] = {"Raj", "Rahul", "Ravi"};
    int ages[] = {30, 35, 40};
    float salaries[] = {30000, 35000, 40000};

    string branchName;
    cout << "Enter branch name: ";
    cin >> branchName;

    for (int i = 0; i < n; i++) {
        branches[i].name = branchNames[i];
        hods[i].name = hodNames[i];
        hods[i].age = ages[i];
        hods[i].salary = salaries[i];
    }

    for (int i = 0; i < n; i++) {
        if (branches[i].name == branchName) {
            cout << "Branch: " << branches[i].name << endl;
            cout << "HOD Name: " << hods[i].name << endl;
            cout << "HOD Age: " << hods[i].age << endl;
            cout << "HOD Salary: " << hods[i].salary << endl;
        }
    }
    return 0;
}