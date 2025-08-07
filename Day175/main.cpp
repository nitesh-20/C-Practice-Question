#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        int maxSum = INT_MIN, currSum = 0;
        int start = 0, tempStart = 0, end = 0;

        for(int i = 0; i < n; i++){
            currSum += arr[i];

            if(currSum > maxSum) {
                maxSum = currSum;
                start = tempStart;
                end = i;
            }

            if(currSum < 0) {
                currSum = 0;
                tempStart = i + 1;
            }
        }
        

        cout << "Maximum Subarray Sum: " << maxSum << endl;
        cout << "Subarray Indices: [" << start << ", " << end << "]" << endl;

        cout << "Subarray Elements: ";
        for(int j = start; j <= end; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}