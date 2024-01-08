class Solution {
public:
    bool inOrder(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr)
            return false;

        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return sum == targetSum;
        }

        return inOrder(root->left, sum, targetSum) || inOrder(root->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return inOrder(root, sum, targetSum);
    }
};
