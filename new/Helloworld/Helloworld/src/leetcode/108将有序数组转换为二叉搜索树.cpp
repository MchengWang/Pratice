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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return used(nums, 0, nums.size() - 1);
    }

    TreeNode* used(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        // 选取中间节点作为根节点
        int mid = (left + right) / 2;

        // 构造一棵以mid位置元素作为节点元素的平衡树
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = used(nums, left, mid - 1);
        root->right = used(nums, mid + 1, right);

        // 返回构建的树
        return root;
    }
};