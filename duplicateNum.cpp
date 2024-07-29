/*There is only one repeated number in nums, return this repeated number.
Input: nums = [1,3,4,2,2]
Output: 2*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int n;
        while(left<=right) {
            if(nums[left]==nums[right]) {
                n=nums[right];
                break;
            }
            right--;
            if(right==left) {
                left=right+1;
                right=nums.size()-1;
                
            }

        }
        return n;
    }
}; 
//shows time limit exceeded 
/*the other method is tortoise and hare algorithm 
we use two pointers */
class solution {
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Finding the intersection point of the two runners.
        int tortoise=nums[0];
        int hare=nums[0];
        do {
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
        } while(tortoise!=hare);
        // Phase 2: Finding the entrance to the cycle.
        tortoise=nums[0];
        while(tortoise!=hare) {
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        return hare;
    }
};