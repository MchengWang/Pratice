#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::vector<int> vecs;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0) continue;
            else
                vecs.push_back(nums[i]);
        }
        size -= vecs.size();
        while (size--)
            vecs.push_back(0);


        nums = vecs;
    }
};