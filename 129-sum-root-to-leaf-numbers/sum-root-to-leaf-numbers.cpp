class Solution {
public:
    void dfs(TreeNode* root, string path, int &sum) {
        if (root == NULL)
            return;

        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            sum += stoi(path);
        }
        dfs(root->left, path, sum);
        dfs(root->right, path, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, "", sum);
        return sum;
    }
};