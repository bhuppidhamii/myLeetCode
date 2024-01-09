class Solution {
public:
    void solve(TreeNode* root, vector<int>&s) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            s.push_back(root->val);
            return;
        }
        solve(root->left, s);
        solve(root->right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1;
        solve(root1, s1);
        vector<int> s2;
        solve(root2, s2);
        return s1==s2;
    }
};