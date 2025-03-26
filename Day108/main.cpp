// Question 1: Library Book Borrowing System**
// Create a structure ⁠ Book ⁠ with members ⁠ id ⁠, ⁠ title ⁠, and a pointer to a structure ⁠ Borrower ⁠. The ⁠ Borrower ⁠ structure should have members ⁠ name ⁠ and ⁠ returnDate ⁠ (an integer representing days until return). Use pointers to dynamically allocate memory for one book and its borrower, prompt the user to input the book’s ID, title, borrower’s name, and return date, and then display all details.

#include<iostream>
#include<string>
using namespace std;

struct Borrower{
    string name;
    int returnDate;
};
struct Book{
    int id;
    string title;
    Borrower* borrower;
};

int main(){
    
}