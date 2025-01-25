/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),right(right) {}
};

class Solution {
public:
    void tracePaths(TreeNode* root, std::vector<std::string>& vecs,
        std::string str) {
        if (root == nullptr)
            return;

        str += std::to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            vecs.push_back(str);
            return;
        }

        str += "->";

        tracePaths(root->left, vecs, str);

        tracePaths(root->right, vecs, str);
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> vecs;
        tracePaths(root, vecs, "");
        return vecs;
    }
};