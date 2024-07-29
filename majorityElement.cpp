/*The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findCandidate(vector<int>& nums) {
        int maxCount=0;
        int index=-1;
        for (int i=0;i<nums.size();i++) {
            int count=0;
            for(int j=0;j<nums.size();j++) {
                if(nums[i]==nums[j]) {
                    count++;
                }
            }
            if(count>maxCount) {
                maxCount=count;
                index=nums[i];
            }
        }
    if(maxCount>nums.size()/2) {
        return index ;
    }
    else {
        return -1;
    }
    }
};

//for large input sets, it shows time exceeeded 
//the other solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;

        // Phase 1: Find the candidate for majority element
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Phase 2: Verify the candidate (optional in this problem, but good for general cases)
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        if (count > nums.size() / 2) {
            return candidate;
        } else {
            return -1; // No majority element
        }
    }
};

//majority elements 
//another que where find all elements that appear more than ⌊ n/3 ⌋ times.
/* Input: nums = [3,2,3]
Output: [3]
Input: nums = [1,2]
Output: [1,2]*/
//use same method as used for above que
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        if(n==0) {
            return {};
        }
       /* if(n<3) {
            return nums;
        }*/
        int c1=0;
        int c2=1;
        int count1=0;
        int count2=0;
        for(int num : nums) {
            if(num==c1) {
                count1++;
            }
            else if(num==c2) {
                count2++;
            }
            else if(count1==0) {
                c1=num;
                count1++;
            }
            else if(count2==0) {
                c2=num;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int num: nums) {
            if(num==c1) {
                count1++;
            }
            else if(num==c2) {
                count2++;
            }
        }
        if(count1>n/3) 
        { result.push_back(c1);
        }
        if(count2>n/3) {
            result.push_back(c2);
        }
        return result;
    }
};
