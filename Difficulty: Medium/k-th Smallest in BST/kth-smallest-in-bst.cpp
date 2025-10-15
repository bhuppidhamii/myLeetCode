
class Solution {
  public:
    int res=-1;
    void solve(Node *root, int &k){
        if(root == NULL) return;
        
        solve(root->left, k);
        k--;
        if(k == 0) {
            res = root->data; 
            return;
        }
        solve(root->right, k);
    }
    int kthSmallest(Node *root, int k) {
        // Jai Shri Ram
        solve(root, k);
        return res;
    }
};