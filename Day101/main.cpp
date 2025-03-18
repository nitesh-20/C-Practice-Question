#include<iostream>
using namespace std;
struct College
{
    string branch;
};
struct HodDetail{
    string name;
    string branch;
    int age;
    float salary;
};
int main(){
        HodDetail h1;
        h1.name="Rahul";
        h1.branch="CSE";
        h1.age=35;
        h1.salary=600;

        HodDetail h2;
        h2.name="Sourabh";
        h2.branch="ECE";
        h2.age=30;
        h2.salary=550;


        HodDetail h3;
        h3.name="Kapil";
        h3.branch="ME";
        h3.age=40;
        h3.salary=650;

        HodDetail h4;
        h4.name="Nitesh";
        h4.branch="AIML";
        h4.age=38;
        h4.salary=620;

        cout<<"HOD Details"<<endl;
        cout<<"Name\tBranch\tAge\tsalary"<<endl;

        cout<<h1.name<<"\t"<<h1.branch<<"\t"<<h1.age<<"\t"<<h1.salary<<endl<<h2.name<<"\t"<<h2.branch<<"\t"<<h2.age<<"\t"<<h2.salary<<endl<<h3.name<<"\t"<<h3.branch<<"\t"<<h3.age<<"\t"<<h3.salary<<endl<<h4.name<<"\t"<<h4.branch<<"\t"<<h4.age<<"\t"<<h4.salary<<endl;

        return 0;
}
