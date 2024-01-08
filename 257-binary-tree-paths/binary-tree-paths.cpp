class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        dfs(root, path, ans);
        return ans;
    }
    void dfs(TreeNode* root, string path, vector<string>& ans) {
        if (root == nullptr)
            return;

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        } else {
            dfs(root->left, path + "->", ans);
            dfs(root->right, path + "->", ans);
        }
    }
};