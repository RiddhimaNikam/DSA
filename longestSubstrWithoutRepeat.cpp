#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t length=s.size();
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;
        unordered_set<char>result;
        result.insert(s[0]);
        int count=1;
        int maxCount=0;
        int left=0;
        for(int i=1;i<length;i++) {
            while(result.find(s[i])!=result.end()) {
                result.erase(s[left]);
                count--;
                left++;
            }
                result.insert(s[i]);
                count++;
            maxCount=max(count,maxCount);
        }
        return maxCount;
        
    }
};
/*Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/