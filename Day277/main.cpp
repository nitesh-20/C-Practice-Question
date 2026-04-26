#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum contiguous subarray sum (Kadane's Algorithm)
int maxSubArraySum(const vector<int>& nums) {
    
    int max_so_far = nums[0];
    int current_max = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        current_max = max(nums[i], current_max + nums[i]);
        max_so_far = max(max_so_far, current_max);
    }
    return max_so_far;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int max_sum = maxSubArraySum(nums);
    cout << "Maximum contiguous subarray sum is: " << max_sum << endl;


    return 0;

}
