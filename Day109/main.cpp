#include <iostream>
using namespace std;

struct Owner
{
    string name;
    int age;
};
struct Book
{
    string name;
    float price;
};
int main()
{
    int n;
    cout << "Enter number of Owner" << endl;
    cin >> n;

    Owner *O1 = new Owner[n];
    Book *B1 = new Book[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details of Owner:-" << i + 1 << endl;
        cout << "Enter name:-";
        cin >> O1[i].name;
        cout << "Enter age:-";
        cin >> O1[i].age;
        cout << "Enter Book Name:-";
        cin >> B1[i].name;
        cout << "Enter Book Price:-";
        cin >> B1[i].price;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Owner " << i + 1 << "Details:-" << endl;
        cout << "Name:-" << O1[i].name<<endl;
        cout << "Age:-" << O1[i].age<<endl;
        cout << "Book Name:-" << B1[i].name<<endl;
        cout << "Price:-" << B1[i].price<<endl;
    }

    return 0;
}