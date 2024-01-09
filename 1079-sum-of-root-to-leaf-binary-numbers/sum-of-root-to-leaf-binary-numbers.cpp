class Solution {
public:
    int res=0;
    int sumRootToLeaf(TreeNode* root) {
        solve(root,0);
        return res;
    }
    void solve(TreeNode* root, int curr){
        if(!root) return;
        curr=(curr*2)+root->val;
        if(root->left==NULL&&root->right==NULL){
            res+=curr;
            return;
        }
        solve(root->left,curr);
        solve(root->right,curr);
    }
};