/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void dfs(Node *root, vector<int>&v){
        if(root!=NULL){
            dfs(root->left, v);
            v.push_back(root->data);
            dfs(root->right, v);
        }
    }
    int findMaxFork(Node* root, int k) {
        // code here
        vector<int>v;
        dfs(root, v);
        int ans = -1;
        for(auto &i:v){
            if(i <= k){
                ans = i;
            }
        }
        return ans;
    }
};