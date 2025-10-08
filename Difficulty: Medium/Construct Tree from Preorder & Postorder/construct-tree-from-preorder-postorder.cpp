/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *solve(int preStart, int postStart, int preEnd, vector<int> &pre, vector<int> &post){
        if(preStart > preEnd) return NULL;
        
        Node * root = new Node(pre[preStart]);
        if(preStart == preEnd){ // only 1 node is there
            return root;
        }
        Node * nextNode = new Node(pre[preStart+1]); // root of left sutree;
        
        // find nextNode in post order traversal
        int j = postStart;
        while(post[j] != nextNode->data){
            j++;
        }
        int num = j-postStart+1;
        
        root->left = solve(preStart+1, postStart, preStart+num, pre, post);
        root->right = solve(preStart+num+1, j+1, preEnd, pre, post);
        
        return root;
    }
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // Jai Shri Ram
        int n = pre.size();
        return solve(0, 0, n-1, pre, post);
    }
};