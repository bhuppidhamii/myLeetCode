/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    #define P pair<int,int>
    P solve(Node *root){
        if(root == NULL) return make_pair(0, 0);
        
        P left = solve(root->left);
        P right = solve(root->right);
        
        int withRoot = root->data + left.second + right.second;
        int withOutRoot = max(left.first, left.second) + max(right.first, right.second);
        
        return make_pair(withRoot, withOutRoot);
    }
    int getMaxSum(Node *root) {
        // Jai Shri Ram
        P ans = solve(root);
        return max(ans.first, ans.second);
    }
};