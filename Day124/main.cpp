#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};

    cout<<"Orignal array: ";
    for(int i=0; i<5; i++)
        cout<<arr[i]<<" ";

        cout<<"\n Reversed array: ";
        for(int i=4; i>=0; i--)
        cout<<arr[i]<<" ";

        return 0;
}