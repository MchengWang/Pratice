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

#include <iostream>

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

    int getMinimumDifference(TreeNode* root) {
        int min = INT_MAX;
        int pre = -1;
        dfs(root , pre , min);
        return min;
    }

    void dfs(TreeNode* root , int& pre , int & min)
    {
        if (root == nullptr) return;
        dfs(root->left , pre , min);
        if (pre == -1) pre = root->val;
        else
        {
            min = min < (root->val - pre) ? min : root->val - pre;
            pre = root->val;
        }

        dfs(root->right , pre , min);
    }

};