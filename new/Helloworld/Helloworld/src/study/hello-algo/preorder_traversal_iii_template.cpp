#include "basic.h"

// 判读是否有解
bool isSolution(std::vector<TreeNode*>& state)
{
	return !state.empty() && state.back()->val == 7;
}

// 记录解
void recordSolution(std::vector<TreeNode*>& state, std::vector<std::vector<TreeNode*>>& res)
{
	res.push_back(state);
}

// 判断在当前状态下，该选择是否合法
bool isValid(std::vector<TreeNode*>& state, TreeNode* choice)
{
	return choice != nullptr && choice->val != 3;
}

// 更新状态
void makeChoice(std::vector<TreeNode*>& state, TreeNode* choice)
{
	state.push_back(choice);
}

// 恢复状态
void undoChoice(std::vector<TreeNode*>& state, TreeNode* choice)
{
	state.pop_back();
}

// 回溯算法:例题三
void backtrack(std::vector<TreeNode*>& state, std::vector<TreeNode*>& choices, std::vector<std::vector<TreeNode*>>& res)
{
	// 检查是否为解
	if (isSolution(state))
		// 记录解
		recordSolution(state, res);
	// 遍历所有选择
	for (TreeNode* choice : choices)
	{
		// 剪枝:检查选择是否合法
		if (isValid(state, choice))
		{
			// 尝试: 做出选择，更新状态
			makeChoice(state, choice);
			// 进行下一轮选择
			std::vector<TreeNode*> nextChoices{ choice->left, choice->right };
			backtrack(state, nextChoices, res);
			// 回退: 撤销选择，恢复到之前的状态
			undoChoice(state, choice);
		}
	}
}