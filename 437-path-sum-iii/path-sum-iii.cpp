class Solution {
public:
    long target;
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        target = targetSum;
        int count = 0;
        inOrder(root, count);
        return count;
    }

    void inOrder(TreeNode* root, int& count) {
        if (root != NULL) {
            solve(root, 0, count);
            inOrder(root->left, count);
            inOrder(root->right, count);
        }
    }

    void solve(TreeNode* root, long sum, int& count) {
        if (root == NULL) return;

        sum += root->val;
        if (sum == target) {
            count++;
        }

        solve(root->left, sum, count);
        solve(root->right, sum, count);
    }
};
