/*Given an array nums with n objects colored red, white, or blue, sort them in-place so
 that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
/*the Dutch National Flag algorithm, proposed by Edsger Dijkstra, is an efficient algorithm for sorting 
an array of elements that can take on one of three distinct values. */