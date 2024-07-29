/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
 The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
 The robot can only move either down or right at any point in time.
 Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D array `dp` with m rows and n columns
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // The bottom-right corner of the grid contains the number of unique paths
        return dp[m-1][n-1];
    }
};
/* the iterations would be 
dp = [
  [1, 1],
  [1, 0],
  [1, 0]
]
dp[1][1] = 1 + 1 = 2
dp = [
  [1, 1],
  [1, 2],
  [1, 0]
]
dp[2][1] = dp[1][1] + dp[2][0]
dp[2][1] = 2 + 1 = 3
dp = [
  [1, 1],
  [1, 2],
  [1, 3]
]
*/
