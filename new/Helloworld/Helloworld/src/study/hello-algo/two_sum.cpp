#include "basic.h"

// 哈希优化
// 暴力枚举
std::vector<int> twoSumBruteForce(std::vector<int>& nums, int target)
{
	int size = nums.size();
	// 两层循环，时间复杂度 O(n^2)
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
		{
			if (nums[i] + nums[j] == target)
				return { i , j };
		}
	return {};
}

// 辅助哈希表
std::vector<int> twoSumHashTable(std::vector<int>& nums, int target)
{
	int size = nums.size();
	// 辅助哈希表，空间复杂度为O(n)
	std::unordered_map<int, int> dic;
	// 单层循环，时间复杂度为O(n)
	for (int i = 0; i < size - 1; i++)
	{
		if (dic.find(target - nums[i]) != dic.end())
			return { dic[target - nums[i]], i };
		dic.emplace(nums[i], i);
	}
	return {};
}