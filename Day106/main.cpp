#include<iostream>
using namespace std;


struct College{
    string name;
};
struct ParticipateDetails{
    string name;
    int age;
    float weight;
    int id;
};

int main(){
    int n=10;
    College* clg = new College[n];
    ParticipateDetails* pd = new ParticipateDetails[n];

    string Collegename[]={"IIT","NIT","IIIT","VIT","MIT","BITS","IIM","IISc","IISER","IIST"};
    string name[]={"Raj", "Rahul", "Rohan","Rajesh","Rakesh","Rajat","Rajeev","Rajiv","Rajnish","Rajendra"};
    int age[] = {25, 30, 35, 40, 45, 50, 55, 60, 65, 70};
    float weight[] = {50, 55, 60, 65, 70, 75, 80, 85, 90, 95};
    int id[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i=0;i<n;i++){
        clg[i].name=Collegename[i];
        pd[i].name=name[i];
        pd[i].age=age[i];
        pd[i].weight=weight[i];
        pd[i].id=id[i];
    }
    for(int i=0;i<=10;i++){
        cout<<"organized by SSIPMT"<<endl;
        cout<<"Function name:Agresita"<<endl;
        cout<<"participated on Wrestling Competition"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"College Name: "<<Collegename[i]<<endl;
        cout<<"Name: "<<pd[i].name<<endl;
        cout<<"Age: "<<pd[i].age<<endl;
        cout<<"Weight: "<<pd[i].weight<<endl;
        cout<<"ID: \n"<<pd[i].id<<endl;
    }
    return 0;
}
