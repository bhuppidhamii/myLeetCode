class Solution {
public:
    int N;
    vector<int>dp;
    bool solve(vector<int>& nums, int i, int jumps, vector<int>&dp) {
        if (i == N - 1) {
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        if (jumps == 0 || i > N - 1)
            return false;
        for (int j = 1; j <= jumps; j++) {
            if (i + j < N && solve(nums, i + j, nums[i + j], dp) == true) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        N = nums.size();
        dp.resize(N+1, -1);
        return solve(nums, 0, nums[0], dp);
        //.         nums, index, jumps
    }
};