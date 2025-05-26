/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    /*You are required to complete this method*/
    int solve(Node *root){
        if(root == nullptr){
            return 0;
        }
        int left= 1+solve(root->left);
        int right=1+solve(root->right);
        return max(left, right);
    }
    int maxDepth(Node *root) {
        // Your code here
        return solve(root);
    }
};
