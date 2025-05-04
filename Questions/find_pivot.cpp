#include <iostream>
#include <vector>
using namespace std;

// Function to find the pivot index
int pivotIndex(const vector<int>& nums) {
    // TODO: Implement the logic here

    int lsum, rsum, pivot;
    lsum = rsum = pivot = 0;

    for(int i=1; i<nums.size(); i++)
    {
        rsum += nums[i];
    }
    
    while(lsum != rsum && pivot<nums.size()-1)
    {
        lsum += nums[pivot];
        pivot++;
        rsum -= nums[pivot];
    }
    if(lsum != rsum) return -1;
    return pivot;
}

int main() {
    // Sample input
    // vector<int> nums = {1, 7, 3, 6, 5, 6};
    vector<int> nums = {2, 5};
    // Call the function
    int result = pivotIndex(nums);

    // Output the result
    cout << "Pivot index: " << result << endl;

    return 0;
}
