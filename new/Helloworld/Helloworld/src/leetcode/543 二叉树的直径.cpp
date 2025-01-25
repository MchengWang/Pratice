struct TreeNode{
 int val;
 TreeNode* left;
 TreeNode* right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int count = 0;
        if (root == nullptr) return 0;
        depath(root, count);
        return count;
    }

    int depath(TreeNode* root , int& count)
    {
        if (root->left == nullptr && root->right == nullptr) return 0;
        int left = 0, right = 0;
        if (root->left) left = depath(root->left, count) + 1;
        if (root->right) right = depath(root->right, count) + 1;
        count = count > (left + right) ? count : (left + right);
        return left > right ? left : right;
    }
};