/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void countNodes(Node *root, int &size){
        if(root!=nullptr){
            countNodes(root->left, size);
            size++;
            countNodes(root->right, size);
        }
    }
    int getSize(Node* root) {
        // Jai Shri Ram
        int size = 0;
        countNodes(root, size);
        return size;
    }
};