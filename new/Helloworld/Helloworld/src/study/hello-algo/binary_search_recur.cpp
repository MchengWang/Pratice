#include "basic.h"

// 二分查查找: 问题 f(i, j)
int dfs(std::vector<int>& nums, int target, int i, int j)
{
	// 若区间为空，代表无目标元素，则返回 -1
	if (i > j)
		return -1;
	// 计算中点索引
	int m = (i + j) / 2;
	if (nums[m] < target)
		// 递归子问题 f(m + 1, j)
		return dfs(nums, target, m + 1, j);
	else if (nums[m] > target)
		// 递归子问题 f(i, m - 1)
		return dfs(nums, target, i, m - 1);
	else
		// 找到目标元素，返回其索引
		return m;
}

// 二分查找
int binarySearch(std::vector<int>& nums, int target)
{
	int n = nums.size();
	// 求解问题 f(0, n - 1)
	return dfs(nums, target, 0, n - 1);
}