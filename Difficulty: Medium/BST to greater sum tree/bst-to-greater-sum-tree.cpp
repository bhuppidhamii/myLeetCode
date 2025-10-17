class Solution {
  public:
    void solve(Node *root, vector<int>&org){
        if(root == NULL) return;
        solve(root->left, org);
        org.push_back(root->data);
        solve(root->right, org);
    }
    void compute(Node *root, map<int,int>&mp){
        if(root!=nullptr){
            compute(root->left, mp);
            root->data = mp[root->data];
            compute(root->right, mp);
        }
    }
    void transformTree(Node *root) {
        // Jai Shri Ram
        // BF
        
        vector<int>org;
        solve(root, org);
        int n=org.size();
        vector<int>mod(n,0);
        for(int i=n-2; i>=0; i--){
            mod[i] = org[i+1] + mod[i+1];
        }
        
        // create map
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[org[i]] = mod[i];
        }
        
        compute(root, mp);
    }
};