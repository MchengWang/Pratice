#include <string>
#include <bitset>

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
    int sumRootToLeaf(TreeNode* root) {

    }

	void pre(TreeNode* root)
	{
		strs->append(std::to_string(root->val));

		if (root->left == nullptr && root->right == nullptr)
		{

			std::bitset<32> b{*strs};
		}
		
		if (root->left != nullptr)
			pre(root->left);
		if (root->right != nullptr)
			pre(root->right);
	}
private:
	int num = 0;
	std::string* strs = new std::string();
};