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

#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x , TreeNode* left , TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> vecs;
    int base, count , maxCount;

    std::vector<int> findMode(TreeNode* root) {
        dfs(root);
        return vecs;
    }

    void dfs(TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        dfs(root->left);
        updateNum(root->val);
        dfs(root->right);
    }

    void updateNum(int i)
    {
        if(i == base) ++ count;
        else
        {
            count = 1;
            base = i;
        }

        if (count == maxCount) vecs.push_back(base);

        if (count > maxCount)
        {
            maxCount = count;
            vecs = std::vector<int>{ base };
        }
    }
};