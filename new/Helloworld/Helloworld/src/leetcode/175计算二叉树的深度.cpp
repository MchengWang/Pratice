#include <iostream>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int calculateDepth(TreeNode* root) {
		depth(root, 0);
		return max_depth;
	}

	void depth(TreeNode* root , int depth_)
	{
		if (root == nullptr) return;
		++depth_;
		max_depth = max_depth > depth_ ? max_depth : depth_;
		depth(root->left, depth_);
		depth(root->right, depth_);
	}
private:
	int max_depth = 0;
};
