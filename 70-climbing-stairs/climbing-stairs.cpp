class Solution {
private:
    int solve(int n, int steps, vector<int> &dp){
        if(steps == n){
            return 1;
        }
        if(steps > n) return 0;

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n]=solve(n-1, steps, dp) + solve(n-2, steps, dp);
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(100,-1);
        int steps=0;
        return solve(n, steps, dp);
    }
};