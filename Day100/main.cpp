#include<iostream>
using namespace std;

struct employee{
    int id;
    char name[30];
    float salary;
};
int main(){
    struct employee emp[3];
    struct employee *ptr=emp;

    for(int i=0;i<3;i++){
        cout<<"Enter details for employee "<<i+1<<endl;
        cout<<"Enter id: ";
        cin>>ptr[i].id;
        cout<<"Enter name: ";
        cin>>ptr[i].name;
        cout<<"Enter salary: ";
        cin>>ptr[i].salary;
        }
        for(int i=0;i<3;i++){
            cout<<"Employee "<<i+1<<" details are: "<<endl;
            cout<<"Id: "<<ptr[i].id<<endl;
            cout<<"Name: "<<ptr[i].name<<endl;
            cout<<"Salary: "<<ptr[i].salary<<endl;
            }
        return 0;
    }
