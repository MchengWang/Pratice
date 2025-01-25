#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) 
    {
        k %= nums.size();

        // 将数组整体翻转
        reverse(nums, 0, nums.size() - 1);
        // 将数组前 k 个翻转
        reverse(nums, 0, k - 1);
        // 将数组余下进行翻转
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(std::vector<int>& nums, int start, int end)
    {
        while (start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};