/* Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(); // The grid is n x n
        vector<int> result;
        vector<int> count(n * n + 1, 0); // Initialize a count array to store the count of each number

        // Iterate over the grid and count the occurrences of each number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

        int miss = -1, repeat = -1;
        for (int i = 1; i <= n * n; i++) {
            if (count[i] == 0) {
                miss = i; // Missing number
            }
            if (count[i] > 1) {
                repeat = i; // Repeated number
            }
        }

        result.push_back(repeat);
        result.push_back(miss);
        return result;
    }
};
