class Solution {
public:
    vector<vector<int>>ans;
    int target;
    void dfs(TreeNode* root,int sum,vector<int>v){
        if(root==NULL) return;

        v.push_back(root->val);
        sum+=root->val;

        if(root->left==NULL && root->right==NULL){
            if(sum==target){
                ans.push_back(v);
            }
        }
        dfs(root->left, sum, v);
        dfs(root->right, sum,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        vector<int>v;
        dfs(root,0,v);
        return ans;
    }
};