#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return ;

        // 分别递归遍历左右子树
        flatten(root->right);
        flatten(root->left);

        // 将当前二叉树结点的右节点指向 cur
        root->right = cur;
        // 题中说明，均无左子节点，则左子节点均置为空
        root->left = nullptr;
        // 将 cur 结点移动一位，继续添加结点
        cur = root;
    }

private:
    TreeNode* cur = nullptr;
};              