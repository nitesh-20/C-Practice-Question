//Define a structure Author with members name and age, and a structure Book with members title, price, and a pointer to an Author structure. Use pointers to dynamically allocate memory for one book and its associated author. Prompt the user to input the book’s title, price, and the author’s name and age, then display all details.

#include<iostream>
using namespace std;
struct Author{
    string name;
    int age;
};

struct Book{
    string title;
    int price;
};
int main(){
    int n=3;
    Author* author1 = new Author[n];
    Book* book1 = new Book[n];

    string AuthorName[]={"Raj", "Rahul", "Rohan"};
    int AuthorAge[] = {25, 30, 35};
    string Tittle[]={"ABC","DEF","GHI"};
    int Price[] = {100,200,300};

    for (int i = 0; i < 3; i++)
    {
        author1[i].name=AuthorName[i];
        author1[i].age=AuthorAge[i];
        book1[i].title=Tittle[i];
        book1[i].price=Price[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"Author Name: "<<author1[i].name<<endl;
        cout<<"Author Age: "<<author1[i].age<<endl;
        cout<<"Book Title: "<<book1[i].title<<endl;
        cout<<"Book Price: "<<book1[i].price<<endl;
    }

    return 0;
}
