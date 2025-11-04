class Solution {
  public:
    int n;
    int solve(int i, vector<int>&height, vector<int>&dp){
        if(i >= n){ // outside
            return INT_MAX;
        }
        if(i == n-1) return 0; // reached last stair
        
        if(dp[i] != -1) return dp[i];
        
        int a=INT_MAX, b=INT_MAX;
        // take i+1
        if(i+1 < n ){
            if(solve(i+1, height, dp)!=INT_MAX){
                a = abs(height[i]-height[i+1]) + solve(i+1, height, dp);
            };
        }
        // take i+2
        if(i+2 < n){
            if(solve(i+2, height, dp)!=INT_MAX){
                b = abs(height[i]-height[i+2]) + solve(i+2, height, dp);
            };
        }
        int ans = min(a, b);
        if(ans == INT_MAX) return 0;
        return dp[i] = ans;
    }
    int minCost(vector<int>& height) {
        // Jai Shri Ram
        n = height.size();
        vector<int>dp(n,-1);
        return solve(0, height, dp);
    }
};