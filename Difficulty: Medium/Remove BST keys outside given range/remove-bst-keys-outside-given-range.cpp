class Solution {
  public:
    void preOrder(Node *root, vector<int>&v, int l, int r){
        if(root!=NULL){
            if(root->data>=l && root->data<=r){
                v.push_back(root->data);
            }
            preOrder(root->left, v, l, r);
            preOrder(root->right, v, l, r);
        }
    }
    
    Node* solve(Node *root, int key){
        if(root == nullptr){
            return new Node(key);
        }else if(key < root->data){
            root->left = solve(root->left, key);
        }else{
            root->right = solve(root->right, key);
        }

        return root;
    }
    
    Node* removekeys(Node* root, int l, int r) {
        // Jai Shri Ram
        
        // BF
        vector<int>v;
        preOrder(root, v, l, r);
        
        // preOrderToBST
        root = NULL;
        for(auto &i:v){
            root = solve(root, i);
        }
        return root;
    }
};