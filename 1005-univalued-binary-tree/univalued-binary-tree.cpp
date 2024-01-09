class Solution {
public:
    void solve(TreeNode* root, set<int>&st){
        if(root!=NULL){
            solve(root->left,st);
            st.insert(root->val);
            solve(root->right,st);
        }
    }
    bool isUnivalTree(TreeNode* root) {
        set<int>st;
        solve(root, st);
        if(st.size()==1){
            return true;
        }
        return false;
    }
};