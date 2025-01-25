/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    bool isSymmetric(TreeNode* root) {
        return isSymmetry(root->left, root->right);
    }

    bool isSymmetry(TreeNode* lchild, TreeNode* rchild)
    {
        if (lchild == nullptr && rchild == nullptr) return true;

        if (lchild == nullptr || rchild == nullptr || lchild->val != rchild->val) return false;

        return isSymmetry(lchild->left, rchild->right) && isSymmetry(lchild->right , rchild->left);
    }
};