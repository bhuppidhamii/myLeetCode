class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        targetSum -= root->val;

        // Check if it's a leaf node and if the remaining targetSum is 0
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
