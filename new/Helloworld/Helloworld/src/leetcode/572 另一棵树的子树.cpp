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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        if(isEqual(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isEqual(TreeNode* source, TreeNode* target)
    {
        if (source == nullptr && target == nullptr) return true;
        if (source == nullptr || target == nullptr) return false;

        return source->val == target->val && isEqual(source->left, target->left) && isEqual(source->right, target->right);

    }
};