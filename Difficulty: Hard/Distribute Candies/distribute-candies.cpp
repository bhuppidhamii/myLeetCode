class Solution {
  public:
    int moves = 0;
    int solve(Node* root){
        if(root == NULL) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        moves += (abs(left) + abs(right)); //  add the extra candies came from l & r
        return (root->data + left + right) - 1; // return extra candies
    }
    int distCandy(Node* root) {
        // Jai Shri Ram
        solve(root);
        return moves;
    }
};