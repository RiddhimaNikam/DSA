#include <iostream>
#include <vector>
using namespace std;
/*int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        while(i< nums.size()) {
            if(nums[i]==val) {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        int s=nums.size();
        return s;
    }
};
/*Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
            while(j<nums.size()) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i]=nums[j];
            } 
             j++;
            }
        nums.resize(i+1);
        int s=nums.size();
        return s;
    }
};

/*Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=2;i<nums.size();i++) {
                if(nums[i]==nums[i-2]) {
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }
        int s=nums.size();
        return s;
    }
};