/*Given an array of integers nums and an integer target, return indices of the two numbers such that they 
add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Input: nums = [3,2,4], target = 6
Output: [1,2]*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target) {
                    result={i,j};
                    break;
                }
            }
        }
        return result;
    }
};

/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints
 of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int width,a;
        int area=0;
        for(int j=0;j<height.size();j++) {
        for(int i=j+1;i<height.size();i++) {
            width=i-j;
            a=width*min(height[j],height[i]);
            if(area<a) {
                area=a;
            }
            
        } }
        return area;
    }
}; //this exceeds time limit for large data sets
//the other solution 
//it is TWO POINTERS METHOD
class Solution {
    public: 
        int maxArea(vector<int>& height) {
            int left=0;
            int right =height.size()-1;
            int max_area=0;
            while(left<right) {
                int width=right-left;
                int h=min(height[left],height[right]);
                int area=width*h;
                max_area=max(area,max_area);
                if(height[left]<height[right]) {
                    left++;
                }
                else{
                    right--;
                }
            }
            return max_area;
        }
};