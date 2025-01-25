#include <iostream>
#include <vector>

/*
    分治法：
    1.划分子区间
    2.求解小问题
    3.汇总问题
*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        andSort(nums, 0, nums.size());
        return true;
    }

    void andSort(std::vector<int>& nums, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            andSort(nums, start, mid);
            andSort(nums, mid + 1, end);
            andSort(nums, start, mid);
        }
    }


    void merge(std::vector<int>& nums, int low, int mid, int hight)  //合并函数
    {
        std::vector<int> temp;  //用 new 申请一个辅助函数
        int i = low, j = mid + 1, k = 0;    // k为 b 数组的小标
        while (i <= mid && j <= hight)
        {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];  //按从小到大存放在 b 数组里面
            else
                temp[k++] = nums[j++];
        }
        while (i <= mid)  // j 序列结束，将剩余的 i 序列补充在 b 数组中 
            temp[k++] = nums[i++];
        while (j <= hight)// i 序列结束，将剩余的 j 序列补充在 b 数组中 
            temp[k++] = nums[j++];
        k = 0;  //从小标为 0 开始传送
        for (int i = low; i <= hight; i++)  //将 b 数组的值传递给数组 a
            nums[i] = temp[k++];
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = { 1, 2, 33, 4, 95, 2, 0 };
    sol.containsDuplicate(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ,";
    }
    std::cin.get();
}