#include<iostream>
using namespace std;

int main(){
    int a[5]={1,2,33,42,53};
    int key;

    cout<<"Enter the key to search: ";
    cin>>key;

    for(int i=0; i<5; i++){
        if(a[i] == key){
            cout<<"Key is found at index: "<<i<<endl;
            
        }
    }
}