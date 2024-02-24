class Solution {
public:
    int n;
    bool solve(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == n - 1)
            return true;
        if (idx >= n)
            return false;
        if (dp[idx] != -1) {
            return dp[idx];
        }
        for (int i = 1; i <= nums[idx]; i++) {
            if (solve(i + idx, nums, dp)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};