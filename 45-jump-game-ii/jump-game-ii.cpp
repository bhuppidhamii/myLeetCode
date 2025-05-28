class Solution {
public:
    int N;
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= N - 1) return 0;
        if (nums[i] == 0) return INT_MAX;
        if (dp[i] != -1) return dp[i];

        int minJumps = INT_MAX;
        for (int j = 1; j <= nums[i] && i + j < N; j++) {
            int next = solve(i + j, nums, dp);
            if (next != INT_MAX) {
                minJumps = min(minJumps, 1 + next);
            }
        }

        return dp[i] = minJumps;
    }

    int jump(vector<int>& nums) {
        N = nums.size();
        vector<int> dp(N, -1);
        return solve(0, nums, dp);
    }
};