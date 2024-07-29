/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the array
        //Facilitates easy duplicate management by making duplicate values adjacent.
        for (int i = 0; i < nums.size(); ++i) {
/*The goal of the problem is to find all unique triplets (or combinations) that meet the criteria
 (e.g., summing to zero).
If duplicates are not handled, your result will include multiple instances of the same triplet, 
which is not desirable.*/
            // Skip duplicate elements for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    // Move both pointers
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left; // We need a larger sum
                } else {
                    --right; // We need a smaller sum
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);
    
    cout << "Triplets that sum up to zero are:" << endl;
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    
    return 0;
}
