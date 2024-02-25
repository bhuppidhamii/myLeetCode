class Solution {
public:
    int solve(int i, vector<int>& nums, int target, vector<int>& dp) {
        if (i == nums.size() - 1) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int maxSteps = INT_MIN;
        for (int j = i + 1; j < nums.size(); j++) {
            if (abs(nums[j] - nums[i]) <= target) {
                maxSteps = max(maxSteps, 1 + solve(j, nums, target, dp));
                dp[i] = maxSteps;
            }
        }
        return dp[i] = maxSteps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(1001, -1);
        int ans = solve(0, nums, target, dp);
        if (ans > 0)
            return ans;
        return -1;
    }
};