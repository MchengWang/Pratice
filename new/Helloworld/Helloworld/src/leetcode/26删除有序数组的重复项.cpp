#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) 
            return 0;
        int top = 1, down = 1;
        while (top < n) {
            if (nums[top] != nums[top - 1]) {
                nums[down] = nums[top];
                ++down;
            }
            ++top;
        }
        return down;
    }
};
