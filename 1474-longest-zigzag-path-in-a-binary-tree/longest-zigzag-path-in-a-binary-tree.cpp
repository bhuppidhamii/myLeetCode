class Solution {
public:
    int sol(TreeNode* root, bool d, int l) {
        if (root == NULL)
            return l;

        if (d == 0) {
            // go right
            return max(sol(root->left, 0, 0), sol(root->right, 1, l + 1));
        } else {
            // go left
            return max(sol(root->left, 0, l + 1), sol(root->right, 1, 0));
        }
    }
    int longestZigZag(TreeNode* root) {
        if (root == NULL)
            return 0;
        // 0 -> left
        // 1 -> right         
        int left = sol(root->left, 0, 0);
        int right = sol(root->right, 1, 0);
        return max(left, right);
    }
};