#include <iostream>
#include <vector>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int val = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int money = 0;
            for (int m : accounts[i]) {
                money += m;
            }
            val = std::max(val, money);
        }
        return val;
    }
};
