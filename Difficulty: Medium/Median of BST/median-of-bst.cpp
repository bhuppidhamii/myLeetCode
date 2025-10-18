class Solution {
  public:
    int N = 0, ans = 0;
    void inOrder(Node *root){
        if(root == NULL) return;
            inOrder(root->left);
            N++;
            inOrder(root->right);
        
    }
    void solve(Node* root, int &curr, int idx){
        if(root == NULL) return;
            solve(root->left, curr, idx);
            curr++;
            if(curr == idx){
                ans = root->data;
                return;
            }
            solve(root->right, curr, idx);
        
    }
    int findMedian(Node* root) {
        // Jai Shri Ram
        inOrder(root);
        int idx = 0;
        if(N%2 == 0){ // even
            idx = N/2;
        }else{
            idx = (N+1)/2; // odd
        }
        int curr = 0;
        solve(root, curr, idx);
        return ans;
    }
};