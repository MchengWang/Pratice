#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // 设置两个指针，分别对应于第一个和最后一个元素
        int left = 0, right = nums.size();
        // 左指针是否小于右指针
        while (left < right) {
            // 如果left位置对应的数值等于val
            if (nums[left] == val) {
                // 将当前位置元素重新赋值为vector最后一个数值
                nums[left] = nums[right - 1];
                // 删除元素后，长度减少
                right--;
            }
            else {
                // 头指针向后走一个
                left++;
            }
        }
        return left;
    }
};