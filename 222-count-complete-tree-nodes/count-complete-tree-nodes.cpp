class Solution {
public:
    int solve(TreeNode* root,int &count){
        if(root!=NULL){
            solve(root->left,count);
            count++;
            solve(root->right,count);
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        int count=0;
        solve(root,count);
        return count;
    }
};