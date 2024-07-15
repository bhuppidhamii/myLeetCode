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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int>cannotBeRoots;
        for(auto d:descriptions){
          int parent=d[0];
          int child=d[1];
          bool isLeft=d[2];

          if(mp.find(parent)==mp.end()){
            mp[parent]=new TreeNode(parent);
          }

          if(mp.find(child)==mp.end()){
            mp[child]=new TreeNode(child);
          }

          if(isLeft){
            mp[parent]->left=mp[child];
          }else{
            mp[parent]->right=mp[child];
          }

          cannotBeRoots.insert(child);
        }
        int parent=0;
        for(auto d:descriptions){
          int p=d[0];
          if(cannotBeRoots.find(p)==cannotBeRoots.end()){
            parent=p;
            break;
          }
        }
        return mp[parent];
    }
};