class Solution {
public:
    int n;
    int solve(int idx, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(target < 0) return INT_MAX; // not possible
        if(target == 0) return 1; // one possible way

        if(dp[idx][target] != -1) return dp[idx][target];
 
        long ans = 0;
        for(int i=idx; i<n; i++){
            long next = solve(i, target - coins[i], coins, dp);
            if(next != INT_MAX){
                ans += next;
            }
        }
        return dp[idx][target] = ans;
    }
    int change(int target, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(0, target, coins, dp);
    }
};