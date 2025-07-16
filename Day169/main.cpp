#include<iostream>
#include<unordered_map>
using namespace std;

    int main(){
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        int arr[n];
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];

        unordered_map<int, int> count;

        for(int i = 0; i < n; i++){
            count[arr[i]]++;
        }
        
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > 1) {
            cout << "First repeating element is: " << arr[i] << endl;
            return 0;
        }
    }   
         cout << "No repeating elements found." << endl;
        }
    }