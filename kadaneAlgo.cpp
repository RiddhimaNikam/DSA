/*Given an integer array nums, find the subarray with the largest sum, and return its sum.
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
subarray [4,-1,2,1]*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int maxSum=nums[0];
        int currentSum=nums[0];
        for(int i=1;i<nums.size();i++) {
            currentSum=max(nums[i],nums[i]+currentSum);
            maxSum=max(maxSum,currentSum);
        }
        return maxSum;
    }
};
/*Kadane's Algorithm is a popular and efficient algorithm used to find the maximum sum of a
 contiguous subarray within a one-dimensional numerical array.
 It operates in linear time, O(n), making it very efficient for large datasets*/