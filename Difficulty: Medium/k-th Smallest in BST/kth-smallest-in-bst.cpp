class Solution {
  public:
    void solve(Node *root, vector<int>&v){
        if(root!=NULL){
            solve(root->left, v);
            v.push_back(root->data);
            solve(root->right, v);
        }
    }
    int kthSmallest(Node *root, int k) {
        // Jai Shri Ram
        // BF
        vector<int>v;
        solve(root, v);
        
        if(k > v.size()) return -1;
        return v[k-1];
    }
};