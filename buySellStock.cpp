/* Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/
#include <vector>
#include <algorithm>
#include <climits> // For the std::max function
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // Handle empty input

        int minPrice = INT_MAX;  // Initialize minPrice to a very large value
        int maxProfit = 0;       // Initialize maxProfit to 0

        for (int price : prices) {
            // Update minPrice if the current price is lower
            if (price < minPrice) {
                minPrice = price;
            }
            // Calculate profit by subtracting minPrice from the current price
            int profit = price - minPrice;
            // Update maxProfit if the current profit is greater
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
