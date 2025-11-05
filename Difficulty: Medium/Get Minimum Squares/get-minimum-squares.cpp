class Solution {
  public:
    int solve(int target, vector<int>&dp){
        if(target < 0) return INT_MAX;
        if(target == 0) return 0;
        
        if(dp[target] != -1) return dp[target];
        
        int ans = INT_MAX;
        for(int i=1; i<=target; i++){
            int next = solve(target - (i*i), dp);
            if(next != INT_MAX){
                ans = min(ans, next + 1);
            }
        }
        return dp[target] = ans;
    }
    int minSquares(int n) {
        // Jai Shri Ram
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};