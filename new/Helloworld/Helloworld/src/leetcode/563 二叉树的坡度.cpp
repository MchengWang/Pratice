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
    int slope = 0;

    int findTilt(TreeNode* root) {
        dfs(root);
        return slope;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        slope += (left - right) > 0 ? (left - right) : - (left - right);
        return left + right + root->val;
    }
};