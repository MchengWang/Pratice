#include <vector>
#include <string>

#define TO_STRING(x) std::to_string(x)
#define FIXTURE "->"

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        int left = 0, right = 0;   // [left, ..., right]
        std::vector<std::string> vstr;
        while (right < nums.size()) {
            if (right + 1 < nums.size() && nums[right + 1] == nums[right] + 1)
                ++right;
            else {
                if (left == right)
                    vstr.emplace_back(TO_STRING(nums[left]));
                else
                    vstr.emplace_back(TO_STRING(nums[left]) + FIXTURE + TO_STRING(nums[right]));
                ++right;
                left = right;
            }
        }
        return vstr;
    }
};