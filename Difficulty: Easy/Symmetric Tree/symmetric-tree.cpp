class Solution {
  public:
    bool check(Node *l, Node* r){
        // if BOTH are NULL
        if(l==NULL && r==NULL) return true;
        
        // if 1 of them is NULL or BOTH are NULL
        if(l==NULL || r==NULL) return false;
        
        if(l->data != r->data){
            return false;
        }
        
        return check(l->left, r->right) && check(l->right, r->left);
    }
    bool isSymmetric(Node* root) {
        // Jai Shree Ram
        return check(root->left, root->right);
    }
};