#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0) continue;
            else nums[i] += nums[i - 1];
        }
        return nums;
    }
};