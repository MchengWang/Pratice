#include "basic.h"

// 二分查找最左一个 target
int binarySearchLeftEdge(std::vector<int>& nums, int target)
{
	// 等价于查找 target 的插入点
	int i = binarySearchInsertion(nums, target);
	// 未找到 target， 返回 -1
	if (i == nums.size() || nums[i] != target)
		return -1;
	// 找到 target ，返回索引 i
	return i;
}

// 二分查找最右一个 target
int binarySearchRightEdge(std::vector<int>& nums, int target)
{
	// 转化未查找最左一个 target + 1
	int i = binarySearchInsertion(nums, target + 1);
	// j 指向最右一个 target， i 指向首个大于 target 的怨怒是
	int j = i - 1;
	// 未找到 target， 返回 -1
	if (j == nums.size() || nums[j] != target)
		return -1;
	// 找到 target ，返回索引 j
	return j;
}