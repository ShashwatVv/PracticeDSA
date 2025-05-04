/*
Problem Statement:

You are given an integer array `nums` where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number in the array. 

If it is, return the index of the largest element.
Otherwise, return -1.

Example:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and 6 >= 2 * 3, 6 >= 2 * 1, 6 >= 2 * 0

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 is not at least twice as large as 3

Constraints:
- 1 <= nums.length <= 50
- 0 <= nums[i] <= 100
- The largest element in nums is unique
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        //if the largest >= 2*second largest
        if(nums.size() == 1) return 0;
        
        int li=0, l2i=1; //li denotes idx of largest ele
                        //l2i is idx of 2nd largest ele
        if(nums[1]>nums[0])
        {
            li  = 1;
            l2i = 0;
        }
        for(int i=2; i<nums.size(); i++)
        {
            if(nums[i]>nums[l2i])
            {
                if(nums[i]>=nums[li])
                {
                    l2i = li;
                    li = i;
                }
                else l2i = i;
            }
        }
        if(nums[li] >= 2*nums[l2i]) return li;
        return -1;
    }
};

int main() {
    vector<int> nums = {3, 6, 1, 0};  // Sample input

    Solution sol;
    int result = sol.dominantIndex(nums);

    cout << "Dominant index: " << result << endl;

    return 0;
}
