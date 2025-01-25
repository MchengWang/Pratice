#include "basic.h"

// 二分查找插入点（无重复元素）
int binarysearchinsertionsimple(std::vector<int>& nums, int target)
{
	int i = 0, j = nums.size() - 1; // 初始化双闭区间 [0, n - 1];
	while (i <= j)
	{
		int m = i + (j - i) / 2; // 计算中点索引 m
		if (nums[m] < target) // 此情况说明 target 在区间[m + 1, j]中
			i = m + 1;
		else if (nums[m] > target) // 此情况说明 target 在区间[i, m - 1]中
			j = m - 1;
		else // 找到目标元素，返回插入点 m
			return m;
	}
	// 未找到 target ，返回插入点 i
	return i;
}

// 二分查找插入点（存在重复元素）
int binarysearchinsertion(std::vector<int>& nums, int target)
{
	int i = 0, j = nums.size() - 1; // 初始化双闭区间 [0, n - 1];
	while (i <= j)
	{
		int m = i + (j - i) / 2; // 计算中点索引 m
		if (nums[m] < target) // 此情况说明 target 在区间[m + 1, j]中
			i = m + 1;
		else if (nums[m] > target) // 此情况说明 target 在区间[i, m - 1]中
			j = m - 1;
		else
			j = m - 1; // 首个小于 target 的元素在区间[i, m - 1]中
	}
	// 返回插入点 i
	return i;
}