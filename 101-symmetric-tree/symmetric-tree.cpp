class Solution {
public:
    bool check(TreeNode* l, TreeNode* r) {
        // if both are null
        if (l == NULL && r == NULL)
            return true;

        // if any one of them is null
        if (l == NULL || r == NULL)
            return false;

        // if both are not null
        if ((l->val == r->val) && check(l->left, r->right) && check(l->right, r->left)) {
            return true;
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};