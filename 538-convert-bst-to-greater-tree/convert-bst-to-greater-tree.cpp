class Solution {
public:
    void solve(TreeNode* root, int &sum){
      if(root!=NULL){
        solve(root->right,sum);
        sum=sum+root->val;
        root->val=sum;
        solve(root->left,sum);
      }
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return root;
    }
};