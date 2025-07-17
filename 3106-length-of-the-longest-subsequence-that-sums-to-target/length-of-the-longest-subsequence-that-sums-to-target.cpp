class Solution {
public:
    int N;
    int solve(int i, vector<int>& nums, int target, vector<vector<int>>&dp){
        if(target == 0) return 0;
        if(target < 0 || i >= N) return INT_MIN;

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        // take 
        int take = 1 + solve(i+1, nums, target-nums[i], dp);
        // if (take != INT_MIN) take = 1 + take;

        // not take
        int skip = solve(i+1, nums, target, dp);

        return dp[i][target] = max(take, skip);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        N = nums.size();
        vector<vector<int>>dp(N+1, vector<int>(target+1, -1));

        int maxLen = solve(0, nums, target, dp);
        if(maxLen <= 0) return -1;
        return maxLen;
    }
};