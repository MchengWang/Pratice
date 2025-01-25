#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int ans = 0;
        int min_price = INT_MAX;
        for (auto price : prices) {
            ans = std::max(ans, price - min_price);
            min_price = std::min(min_price, price);
        }
        return ans;
    }
};