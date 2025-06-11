/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, string path, vector<string>&ans){
        if(root==NULL){
            return;
        }
        path+=to_string(root->val);
        path+="->";
        if(root->left==NULL && root->right==NULL){
            path.pop_back();
            path.pop_back();
            ans.push_back(path);
            return;
        }

        solve(root->left, path, ans);

        solve(root->right, path, ans);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        solve(root,"", ans);
        // for(auto &i:ans){
        //     cout<<i<<" ";
        // }
        return ans;
    }
};