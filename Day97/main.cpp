#include <iostream>
using namespace std;

struct Country {
    string name;
    int code;
};

struct Address {
    string street, city;
    Country *country;
};

struct Student {
    int roll;
    string name;
    Address *address;
};

int main() {
    int n = 5;
    
    Student *students = new Student[n];
    
    string names[] = {"nitesh", "bihari", "saurabh","krishna","suyash"};
    string streets[] = {"street1", "street2", "street3","street4","strreet5"};
    string cities[] = {"rpr", "vizag", "kashmir","vskp","delhi"};
    string countries[] = {"india", "USA", "pakistan","nepal","bhutan"};
    int countryCodes[] = {123, 456, 789,33,33,322};
    
    for (int i = 0; i < n; i++)
     {
        students[i].roll = i + 1;
        students[i].name = names[i];
        students[i].address = new Address;
        students[i].address->street = streets[i];
        students[i].address->city = cities[i];
        students[i].address->country = new Country;
        students[i].address->country->name = countries[i];
        students[i].address->country->code = countryCodes[i];
    }
    
    cout << "student Details: ";
    for (int i = 0; i < n; i++) 
    {
        cout << "Roll: " << students[i].roll << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Address: " << students[i].address->street<< students[i].address->city<< students[i].address->country->name << " (Code: "<< students[i].address->country->code << ")\n";
    }
    
    for (int i = 0; i < n; i++)
     {
        delete students[i].address->country;
        delete students[i].address;
    }
    delete[] students;
    
    return 0;
}