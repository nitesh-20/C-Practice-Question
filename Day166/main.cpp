#include<iostream>
using namespace std;

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int start = 0, end = str.length() - 1;
    
    while(start < end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
    cout << "Reversed string: " << str;
    return 0;
}