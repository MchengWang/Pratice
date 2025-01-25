#include "basic.h"

TreeNode* dfs(std::vector<int>& preorder, std::unordered_map<int, int>& inorderMap, int i, int l, int r)
{
	// 子树区间为空时终止
	if (r - l < 0)
		return nullptr;
	// 初始化根节点
	TreeNode* root = new TreeNode(preorder[i]);
	// 查询 m ，从而划分左右子树
	int m = inorderMap[preorder[i]];
	// 子问题:构建左子树
	root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
	// 子问题:构建右子树
	root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
	// 返回根节点
	return root;
}

// 构建二叉树
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
	// 初始化哈希表，存储 inorder 元素到索引的映射
	std::unordered_map<int, int> inorderMap;
	for (int i = 0; i < inorder.size(); i++)
		inorderMap[inorder[i]] = i;
	TreeNode* root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
	return root;
}