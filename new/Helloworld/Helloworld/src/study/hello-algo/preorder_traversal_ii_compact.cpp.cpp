#include "basic.h"

class PTIICompact
{
public:
	// 前序遍历:例题二
	void preOrder(TreeNode* root)
	{
		if (root == nullptr) return;
		// 尝试
		path.push_back(root);
		if (root->val == 7)
			// 记录解
			res.push_back(root);
		preOrder(root->left);
		preOrder(root->right);
		// 回退
		path.pop_back();
	}

private:
	std::vector<TreeNode*> res, path;
};