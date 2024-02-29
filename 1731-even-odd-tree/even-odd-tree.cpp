class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> lvl;
            while (n--) {
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
            ans.push_back(lvl);
        }
        for (auto v : ans) {
            for (auto i : v) {
                cout << i << " ";
            }
            cout << "\n";
        }

        for (int i = 0; i < ans.size(); i++) {
            int n = ans[i].size();
            if (n == 1 && ans[0][0] % 2 == 0) {
                return false;
            }
            if (i % 2 == 0) {
                // even-index
                if (ans[i][0] % 2 == 0)
                    return false;
                for (int j = 1; j < n; j++) {
                    if (ans[i][j] % 2 == 0) {
                        return false;
                    }
                    if (ans[i][j - 1] >= ans[i][j]) {
                        return false;
                    }
                }
            } else {
                // odd-index
                if (ans[i][0] % 2 == 1)
                    return false;
                for (int k = 1; k < n; k++) {
                    if (ans[i][k] % 2 == 1)
                        return false;

                    if (ans[i][k - 1] <= ans[i][k]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};