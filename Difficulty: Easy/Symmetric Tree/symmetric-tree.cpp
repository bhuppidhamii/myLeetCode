/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    void solveL(Node *root, vector<int>&L){
        if(root!=NULL){
            solveL(root->left, L);
            L.push_back(root->data);
            solveL(root->right, L);
        }
    }
    void solveR(Node *root, vector<int>&R){
        if(root!=NULL){
            solveR(root->right, R);
            R.push_back(root->data);
            solveR(root->left, R);
        }
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(root == NULL){
            return true;
        }
        
        vector<int>L;
        if(root->left){
            solveL(root->left, L);
        }
        
        
        vector<int>R;
        if(root->right){
            solveR(root->right, R);
        }
        
        return L == R;
    }
};