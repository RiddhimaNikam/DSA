/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
Input: nums = [1,2,3], k = 3
Output: 2*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
       int n=nums.size();
       vector<int>prefix_sum(n+1,0);
       for(int i=0;i<n;i++) {
        prefix_sum[i+1]=prefix_sum[i]+nums[i];
       }
       int count=0;
       for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
           int sum_subarray=prefix_sum[j+1]-prefix_sum[i];
           if(sum_subarray==k) {
            count ++;
           }       
         }  }
        return count;
    }
};