/*Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]*/
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        k = k % N;  // Normalize k to handle cases where k > N

        if (k == 0) return;  // If k is 0, no rotation is needed

        // Temporary vector to hold the last k elements
        vector<int> toMove(nums.end() - k, nums.end());

        // Remove the last k elements from the original vector
        nums.erase(nums.end() - k, nums.end());

        // Insert the last k elements at the beginning of the vector
        nums.insert(nums.begin(), toMove.begin(), toMove.end());
    }
};
