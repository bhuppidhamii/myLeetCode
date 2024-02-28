class Solution {
public:
    TreeNode * ans;
    TreeNode * solve(TreeNode* cloned, TreeNode* target){
        if(cloned==NULL) return cloned;

        if(cloned->val==target->val){
            ans=cloned;
        }
        solve(cloned->left,target);
        solve(cloned->right,target);

        return ans;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(cloned,target);
    }
};