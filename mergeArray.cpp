#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        nums1.resize(m);
        while (j < n) {
            // If all elements in nums1 are processed or the current element in nums2 should be inserted
            if (i == nums1.size() || nums1[i] > nums2[j]) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
            }
            i++;
        }
        nums1.resize(n+m);
    }
};
int main() {
    // Example 1
    vector<int> nums1_1 = {0};
    vector<int> nums2_1 = {1};
    int m1 = 0;
    int n1 = 1;

    Solution sol;
    sol.merge(nums1_1, m1, nums2_1, n1);

    cout << "Merged array 1: ";
    for (int num : nums1_1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums1_2 = {3, 6, 8, 0, 0, 0};
    vector<int> nums2_2 = {4,5, 7, 8};
    int m2 = 3;
    int n2 = 4;

    sol.merge(nums1_2, m2, nums2_2, n2);

    cout << "Merged array 2: ";
    for (int num : nums1_2) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}