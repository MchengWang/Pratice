#include "basic.h"

class PTICompact
{
public:
	// 前序遍历:例题一
	void preOrder(TreeNode* root)
	{
		if (root == nullptr) return;
		if (root->val == 7)
			// 记录解
			res.push_back(root);
		preOrder(root->left);
		preOrder(root->right);
	}

private:
	std::vector<TreeNode*> res;
};