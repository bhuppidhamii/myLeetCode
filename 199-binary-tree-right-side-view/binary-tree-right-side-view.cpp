class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> arr;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> v;
            while (n--) {
                TreeNode* node = q.front();
                v.push_back(node->val);
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            arr.push_back(v);
        }
        vector<int> ans;
        for (auto& a : arr) {
            int n = a.size();
            ans.push_back(a[n - 1]);
        }
        return ans;
    }
};