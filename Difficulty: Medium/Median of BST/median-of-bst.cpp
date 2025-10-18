class Solution {
  public:
    void inOrder(Node* root, vector<int>&v){
        if(root!=NULL){
            inOrder(root->left, v);
            v.push_back(root->data);
            inOrder(root->right, v);
        }
    }
    int findMedian(Node* root) {
        // Jai Shri Ram
        vector<int>v;
        inOrder(root, v);
        
        for(auto &i:v){
            // cout<<i<<" ";
        }
        
        int N = v.size();
        if(N%2 == 0){
            int idx = (N+1)/2;
            idx--;
            return v[idx];
        }
        return v[(N/2)];
    }
};