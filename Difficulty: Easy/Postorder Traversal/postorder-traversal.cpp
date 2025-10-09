class Solution {
  public:
    void solve(Node* root, vector<int>&result){
        if(root == NULL) return;
        solve(root->left, result);
        solve(root->right, result);
        result.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // Jai Shri Ram
        vector<int>result;
        solve(root, result);
        return result;
    }
};