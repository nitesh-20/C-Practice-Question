//Create a structure Employee with members id, name, and a pointer to the next employee. Using pointers and dynamic memory allocation, build a linked list of 3 employees. Prompt the user to input each employee’s ID and name, link them into a list, and then print all employee details in the order they were entered.

#include<iostream>
using namespace std;
struct Employee{
    int ID;
    string name;
    union Data{
        Employee* nextEmployee;
        int val;
    }Data;
};
int main(){
    int n;
    cout<<"Enter the number of Employee: "<<endl;
    cin>>n;
    Employee* emp1 = new Employee[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the ID number of Employees :"<<i+1<<endl;
        cin>>emp1[i].ID;
        cout<<"Enter the name of Employees :"<<i+1<<endl;
        cin>>emp1[i].name;
    }
    cout<<"The details of the Employees are: "<<endl;
    for(int i=1;i<n;i++){
        cout<<"ID number: "<<emp1[i].ID<<endl;
        cout<<"Name: "<<emp1[i].name<<endl;
    }
    return 0;
}