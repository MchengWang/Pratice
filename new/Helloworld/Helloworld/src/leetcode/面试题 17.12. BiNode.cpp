#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    //ans用于返回结果，cur用于记录前一个节点
    TreeNode* ans = new TreeNode(0), * cur = ans;
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        node->left = nullptr;
        cur->right = node;
        cur = node;  //更新cur
        dfs(node->right);
    }

public:
    TreeNode* convertBiNode(TreeNode* root) {
        dfs(root);
        return ans->right;
    }
};