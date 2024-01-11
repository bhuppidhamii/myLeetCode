class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, vector<int> v) {
        if (root == NULL)
            return;

        v.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(v);
            return;
        }

        solve(root->left, v);
        solve(root->right, v);
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v;
        solve(root, v);

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        // return 0;

        vector<int> m;
        for (int i = 0; i < ans.size(); i++) {

            int maxi = INT_MIN;
            for (int j = 0; j < ans[i].size(); j++) {
                for (int k = j + 1; k < ans[i].size(); k++) {
                    int diff = abs(ans[i][j] - ans[i][k]);
                    maxi = max(maxi, diff);
                }
            }
            m.push_back(maxi);
        }
        return *max_element(m.begin(), m.end());
    }
};