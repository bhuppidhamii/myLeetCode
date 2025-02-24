class Solution {
public:
    void dfs(vector<int>& ans, int level, TreeNode* root) {
        if (!root)
            return;

        if (ans.size() < level) {
            ans.push_back(root->val);
        }

        dfs(ans, level + 1, root->right);
        dfs(ans, level + 1, root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 1;
        dfs(ans, level, root);

        return ans;
    }
};