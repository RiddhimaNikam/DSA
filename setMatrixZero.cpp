/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.*/
#include <iostream>
#include <vector>
#include <algorithm> // For std::find

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r;
        vector<int> c;
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Find all rows and columns that need to be zeroed
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    if (find(r.begin(), r.end(), i) == r.end()) {
                        r.push_back(i);
                    }
                    if (find(c.begin(), c.end(), j) == c.end()) {
                        c.push_back(j);
                    }
                }
            }
        }
        
        // Set all cells in identified rows to zero
        for (int i : r) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = 0;
            }
        }
        
        // Set all cells in identified columns to zero
        for (int j : c) {
            for (int i = 0; i < row; i++) {
                matrix[i][j] = 0;
            }
        }
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 0, 6, 7}, {8, 9, 10, 0}};
    sol.setZeroes(matrix);
    
    cout << "Matrix after setting zeroes:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
