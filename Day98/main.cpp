#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int roll;
    char name[20];
    Student* next;
};

Student* head = NULL;

void insert(int roll, const char* name) {
    Student* temp = new Student();
    temp->roll = roll;
    strcpy(temp->name, name);
    temp->next = head;
    head = temp;
}

void print() {
    Student* temp = head;
    while (temp != NULL) {
        cout << temp->roll << " " << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    insert(1, "A");
    insert(2, "B");
    insert(3, "C");

    print();
    
    return 0;
}
