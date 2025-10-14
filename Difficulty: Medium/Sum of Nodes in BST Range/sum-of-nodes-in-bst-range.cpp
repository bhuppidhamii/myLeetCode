
class Solution {
  public:
    int sum = 0;
    void inOrder(Node* root, int l, int r){
        if(root == NULL) return;
        
        inOrder(root->left, l, r);
        if(root->data>=l && root->data<=r){
            sum+=root->data;
        }
        inOrder(root->right, l, r);
    }
    int nodeSum(Node* root, int l, int r) {
        inOrder(root, l, r);
        return sum;
    }
};
