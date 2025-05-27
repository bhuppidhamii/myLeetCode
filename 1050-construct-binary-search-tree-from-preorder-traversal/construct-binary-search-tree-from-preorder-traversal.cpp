class Solution {
public:
    TreeNode* solve(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        } else if (key < root->val) {
            root->left = solve(root->left, key);
        } else {
            root->right = solve(root->right, key);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int N = preorder.size();
        TreeNode* root = nullptr;

        for (auto& key : preorder) {
            root = solve(root, key);
        }
        return root;
    }
};