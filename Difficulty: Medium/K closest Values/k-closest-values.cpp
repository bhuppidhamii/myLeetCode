class Solution {
  public:
    void inOrder(Node* root, vector<int>&v){
        if(root!=NULL){
            inOrder(root->left, v);
            v.push_back(root->data);
            inOrder(root->right, v);
        }
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        // Jai Shri Ram
        vector<int>v;
        inOrder(root, v);
        
        sort(begin(v), end(v), [&target](auto &a, auto &b){
            if(abs(a-target) == abs(b-target)){
                return a < b;
            }
            return abs(a-target) < abs(b-target);
        });
        
        vector<int>ans;
        for(int i=0; i<v.size() && k-- ; i++){
            ans.push_back(v[i]);
        }
        return ans;
    }
};