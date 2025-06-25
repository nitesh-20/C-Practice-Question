#include<iostream>
using namespace std;

int main(){
    int num, binary = 0, place = 1;

    cout<<"Enter a decimal number: ";
    cin >> num;

    while (num > 0){
        int rem = num % 2;
        binary += rem * place;
        place *= 10;
        num /= 2;
    }
    cout << "Binary equivalent: " << binary << endl;
    return 0;
}