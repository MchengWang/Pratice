#include <vector>

class Solution {
public:
    bool canAliceWin(std::vector<int>& nums) {
        int num = 0;
        for (int n : nums)
        {
            num += n < 10 ? n : -n;
        }

        return (bool)num;
    }
};