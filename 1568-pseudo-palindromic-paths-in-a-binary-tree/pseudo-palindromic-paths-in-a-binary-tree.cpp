class Solution {
public:
    int ans;
    void solve(TreeNode* root, vector<int>& v) {
        if (root == nullptr)
            return;

        v[root->val]++;

        if (root->left == NULL && root->right == NULL) {
            int cnt = 0;
            for (int i = 1; i < 10; i++) {
                if (v[i] % 2 != 0) {
                    cnt++;
                }
            }
            if (cnt <= 1) {
                ans++;
            }
        }

        solve(root->left, v);
        solve(root->right, v);

        v[root->val]--;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> v(10, 0);
        ans = 0;
        solve(root, v);
        return ans;
    }
};