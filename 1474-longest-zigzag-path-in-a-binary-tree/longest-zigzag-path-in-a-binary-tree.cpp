class Solution {
public:
    int maxPath = 0;
    void solve(TreeNode* root, int l, bool goLeft) {
        if (root == NULL)
            return;
        maxPath = max(l, maxPath);

        if (goLeft == true) {
            solve(root->left, l + 1, false);
            solve(root->right, 1, true);
        } else {
            solve(root->right, l + 1, true);
            solve(root->left, 1, false);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root, 0, true);
        solve(root, 0, true);

        return maxPath;
    }
};