class Solution {
  public:
    int max_sum = INT_MIN;
    int solve(Node *root){
        if(root == NULL) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        // case 1 -> left & right se aacha sum aya h / niche hi mi gya ans
        int sum1 = left + right + root -> data;
        
        // case 2 -> left ya right m se jo aacha h / koi ek aacha h
        int sum2 = root->data + max(left, right);
        
        // case 3 -> sirf root aacha h
        int sum3 = root->data;
        
        // compute max_sum
        max_sum = max({max_sum, sum1, sum2, sum3});
        
        // most important part
        // We are not sending sum1 because we think sum1 is already the best answer
        return max(sum2, sum3);
    }
    int findMaxSum(Node *root) {
        // Jai Shri Ram
        solve(root);
        
        return max_sum;
    }
};