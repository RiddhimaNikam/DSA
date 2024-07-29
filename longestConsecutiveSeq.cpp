#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(),nums.end());
        int Mcount=0;
        for(int num: numSet) {
            if(numSet.find(num-1)==numSet.end()) {
                int currentNum=num;
                int count=1;
            
            while(numSet.find(currentNum+1)!=numSet.end()) {
                currentNum+=1;
                count+=1;
            }
            Mcount=max(Mcount,count);
        }
    } 
    return Mcount;
    }
};