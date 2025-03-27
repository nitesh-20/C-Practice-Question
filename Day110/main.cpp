// Create a structure Book with members id, title, and a pointer to a structure Borrower. The Borrower structure should have members name and returnDate (an integer representing days until return). Use pointers to dynamically allocate memory for one book and its borrower, prompt the user to input the book’s ID, title, borrower’s name, and return date, and then display all details.
#include <iostream>
using namespace std;

struct Borrower
{
    string name;
    int returnDate;
};
struct Book
{
    int ID;
    string Tittle;
};
int main()
{
    int n;
    cout << "Enter number of borrowers" << endl;
    cin >> n;

    Borrower *Borr1 = new Borrower[n];
    Book *B1 = new Book[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter details of borrowers:" << i + 1 << endl;
        cout << "Enter name:-";
        cin >> Borr1[i].name;
        cout << "Enter returning date:-";
        cin >> Borr1[i].returnDate;
        cout << "Enter ID:-";
        cin >> B1[i].ID;
        cout << "Enter Tittle:-";
        cin >> B1[i].Tittle;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Borrowers" << i + 1 << "Details:-" << endl;
        cout << "Name:-" << Borr1[i].name<<endl;
        cout << "ReturningDate:-" << Borr1[i].returnDate<<endl;
        cout << "ID:-" << B1[i].ID<<endl;
        cout << "Tittle:-" << B1[i].Tittle<<endl;
    }

    return 0;
}