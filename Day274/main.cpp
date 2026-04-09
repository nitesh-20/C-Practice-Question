#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    // TODO: Implement your logic here
    // Hint: Try using a two-pointer approach (left and right)
    
    return 0;
}

int main() {
    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    vector<int> h2 = {1,1};
    
    cout << "Input 1 Output: " << maxArea(h1) << " (Expected: 49)" << endl;
    cout << "Input 2 Output: " << maxArea(h2) << " (Expected: 1)" << endl;
    
    return 0;
}
