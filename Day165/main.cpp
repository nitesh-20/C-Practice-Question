#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<< "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i<n; i++)
        cin >> arr[i];

        int maxSum = INT_MIN, currSum = 0;

        for(int i = 0; i < n; i++){
            currSum += arr[i];
            if(currSum > maxSum)
            maxSum = currSum;
            if(currSum < 0)
            currSum = 0;
        }
        cout << "Maximum subarray sum is: " << maxSum << endl;
    
    return 0;
}