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
    int maxLevelSum(TreeNode* root) {
        // level order traversal
        queue<TreeNode*>q;
        q.push(root);
        int lvl = 1;
        int maxSum = INT_MIN;
        int ansLvl = -1;
        while(q.size()>0){
            int sz = q.size();
            int sum = 0;
            for(int i=0; i<sz; i++){
                TreeNode * node = q.front();
                sum+=node->val;
                q.pop();

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            // cout<<sum<<" ";
            if(sum > maxSum){
                ansLvl = lvl;
                maxSum = sum;
            }
            lvl++;
        }
        return ansLvl;
    }
};