class Solution {
public:
    TreeNode* solve(vector<int>& nums, int s, int e, int n) {
        if (s > e) {
            return NULL;
        }
        int mid = (s + e + 1) / 2; // e=n-1

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(nums, s, mid - 1, n);
        root->right = solve(nums, mid + 1, e, n);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        return solve(nums, s, e, n);
    }
};