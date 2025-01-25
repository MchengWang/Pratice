#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int result = 0, count = 0;
        for (auto num : nums)
        {
            if (count == 0) result = num;
            if (num == result) count += 1;
            else count -= 1;
        }
        return result;
    }
};