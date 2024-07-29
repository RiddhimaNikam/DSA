#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of pairs where each pair contains a height and its corresponding name
        vector<pair<int, string>> heightNamePair;
        for (int i = 0; i < names.size(); i++) {
            heightNamePair.push_back({heights[i], names[i]});
        }

        // Sort the vector of pairs in descending order by height
        sort(heightNamePair.begin(), heightNamePair.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first; // Compare heights in descending order
        });

        // Extract the sorted names into a result vector
        vector<string> sortedNames;
        for (const auto& p : heightNamePair) {
            sortedNames.push_back(p.second);
        }

        return sortedNames;
    }
};

int main() {
    Solution sol;
    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<int> heights = {165, 180, 175};

    vector<string> sortedNames = sol.sortPeople(names, heights);

    cout << "Sorted names by height: ";
    for (const string& name : sortedNames) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}
