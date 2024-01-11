class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root, int mini, int maxi) {
        if (root == NULL) {
            return;
        }

        mini = min(root->val, mini); 
        maxi = max(root->val, maxi); 
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(abs(maxi - mini));
            return;
        }

        solve(root->left, mini, maxi);
        solve(root->right, mini, maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        solve(root, mini, maxi);

        return *max_element(ans.begin(), ans.end());
    }
};