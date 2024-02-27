class Solution {
public:
    int maxi = INT_MIN;
    int solve(TreeNode* root, int& diameter) {
        if (root == NULL)
            return 0;

        int lh = 0, rh = 0;
        lh = solve(root->left, diameter);
        rh = solve(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
};