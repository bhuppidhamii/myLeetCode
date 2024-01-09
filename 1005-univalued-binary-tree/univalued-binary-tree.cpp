class Solution {
public:
    bool solve(TreeNode* root, int& n) {
        if (root == NULL)
            return true;

        if (root->val != n)
            return false;

        return solve(root->left, n) && solve(root->right, n);
    }
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL)
            return true;
        int n = root->val;
        return solve(root, n);
    }
};