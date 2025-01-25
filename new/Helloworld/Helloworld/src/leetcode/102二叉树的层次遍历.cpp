#include <vector>
#include <queue>

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
	std::vector<std::vector<int>> levelOrder(TreeNode* root) {
		std::queue<TreeNode*> que;
		std::vector<std::vector<int>> vecs;
		if (root != nullptr) que.push(root);
		while (!que.empty()) {
			std::vector<int> temp;
			for (int i = que.size(); i > 0; --i) {
				root = que.front();
				que.pop();
				temp.push_back(root->val);
				if (root->left != nullptr) que.push(root->left);
				if (root->right != nullptr) que.push(root->right);
			}
			vecs.push_back(temp);
		}
		return vecs;
	}
};