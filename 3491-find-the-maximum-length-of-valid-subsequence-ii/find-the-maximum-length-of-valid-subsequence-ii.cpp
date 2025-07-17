class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        vector<vector<int>>dp(k, vector<int>(N+1, 1));
        int maxSub = 1;

        for(int i=1; i<N; i++){
            for(int j=0; j<i; j++){
                int mod = (nums[i] + nums[j]) % k;
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);

                maxSub = max(maxSub, dp[mod][i]);
            }
        }
        return maxSub;
    }
};