#include <bits/stdc++.h>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged_array;
        int i=0;
        int j=0;
        while(j<nums2.size() && i<nums1.size()) {
            if(nums1[i]>=nums2[j] ) {
                merged_array.push_back(nums2[j]);
                j++;
            }
            else {
                merged_array.push_back(nums1[i]);
                i++;
            }
        }
        while(i<nums1.size()) {
            merged_array.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()) {
            merged_array.push_back(nums2[j]);
            j++;
        }
        int n=merged_array.size();
        if(n % 2 == 0) {
            return (merged_array[n/2-1] + merged_array[n/2])/2.0;
        }
        else {
            return merged_array[n/2];
        }
    }
};
int main() {
    Solution sol;
    std::vector<int> nums1 = {1};
    std::vector<int> nums2 = {2, 3};

    double result = sol.findMedianSortedArrays(nums1, nums2);
    std::cout << "Median: " << result << std::endl;

    return 0;
}