class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int lastVal = 0;
            while (n--) {
                TreeNode* node = q.front();
                lastVal = node->val;
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(lastVal);
        }

        return ans;
    }
};