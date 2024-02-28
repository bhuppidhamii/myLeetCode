class Solution {
public:
    int maxDepth = -1;
    int ans = 0;
    void dfs(TreeNode* root, int currDepth) {
        if (!root) return;

        if (currDepth > maxDepth) {
            ans = root->val;
            maxDepth = currDepth;
        }

        dfs(root->left, 1 + currDepth);
        dfs(root->right, 1 + currDepth);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};