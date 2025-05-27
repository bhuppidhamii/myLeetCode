/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int count;
    void inorder(Node *root){
        if(root != NULL){
            inorder(root->left);
            if(root->left == NULL && root->right==NULL){
                count++;
            }
            inorder(root->right);
        }
    }
    int countLeaves(Node* root) {
        // write code here
        count = 0;
        inorder(root);
        return count;
    }
};