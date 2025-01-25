#include "basic.h"

// 回溯算法：全排列 II
void backtrack(std::vector<int>& state, const std::vector<int>& choices, std::vector<bool>& selected,
	std::vector<std::vector<int>>& res)
{
	// 当状态长度等于元素数量时，记录解
	if (state.size() == choices.size())
	{
		res.push_back(state);
		return;
	}
	// 遍历所有选择
	std::unordered_set<int> duplicated;
	for (int i = 0; i < choices.size(); i++)
	{
		int choice = choices[i];
		// 剪枝：不允许重读选择元素 且 不允许重复选择相等元素
		if (!selected[i] && duplicated.find(choice) == duplicated.end())
		{
			// 尝试：做出选择，更新状态
			duplicated.emplace(choice); // 记录选择过的元素值
			selected[i] = true;
			state.push_back(choice);
			// 进行下一轮选择
			backtrack(state, choices, selected, res);
			// 回退：撤销选择，恢复到之前的状态
			selected[i] = false;
			state.pop_back();
		}
	}
}

// 全排列 II
std::vector<std::vector<int>> permutationsII(std::vector<int> nums)
{
	std::vector<int> state;
	std::vector<bool> selected(nums.size(), false);
	std::vector<std::vector<int>> res;
	backtrack(state, nums, selected, res);
	return res;
}