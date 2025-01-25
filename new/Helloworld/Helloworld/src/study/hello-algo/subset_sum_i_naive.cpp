#include "basic.h"

// 回溯算：子集和 I
void backtrack(std::vector<int>& state, int target, int total, std::vector<int>& choices,
	std::vector<std::vector<int>>& res)
{
	// 子集和等于 target 时，记录解
	if (total == target)
	{
		res.push_back(state);
		return;
	}
	// 遍历所有选择
	for (size_t i = 0; i < choices.size(); i++)
	{
		// 剪枝：若子集和超过 target ，则跳过该选择
		if (total + choices[i] > target)
			continue;
		// 尝试：做出选择，更新元素和 total
		state.push_back(choices[i]);
		// 进行下一轮选择
		backtrack(state, target, total + choices[i], choices, res);
		// 回退：撤销选择，恢复到之前的状态
		state.pop_back();
	}
}

// 求解子集和 Ｉ　(包含重复子集)
std::vector<std::vector<int>> subsetSumINaive(std::vector<int>& nums, int target)
{
	std::vector<int> state; // 状态（子集）
	int total = 0; // 子集和
	std::vector<std::vector<int>> res; // 结果列表（子集列表）
	backtrack(state, target, total, nums, res);
	return res;
}