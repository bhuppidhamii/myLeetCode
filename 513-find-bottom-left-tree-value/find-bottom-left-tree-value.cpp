class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // level order traversal
        vector<vector<int>> lvls;
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> lvl;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

                lvl.push_back(node->val);
            }
            lvls.push_back(lvl);
        }
        int n=lvls.size();
        return lvls[n-1][0];
    }
};