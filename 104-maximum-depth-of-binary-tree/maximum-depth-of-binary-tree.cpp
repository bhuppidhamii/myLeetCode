class Solution {
public:
    int maxDepth(TreeNode* root) { return solve(root); }
    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return max(1 + solve(root->left), 1 + solve(root->right));
    }
};