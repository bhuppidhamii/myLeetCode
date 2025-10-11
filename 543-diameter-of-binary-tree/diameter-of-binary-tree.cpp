class Solution {
public:
    int maxi;
    int solve(TreeNode *root){
        if(root == nullptr) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        maxi = max(maxi, left+right);
        
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return maxi;
    }
};