class Solution {
  public:
    int n;
    int solve(int i, vector<int>& arr, int last_idx, vector<vector<int>>&dp){
        if(i >= n) return 0;
        
        if(dp[i][last_idx+1] != -1) return dp[i][last_idx+1];
        
        // take
        int take = 0;
        if(last_idx == -1 || arr[i] > arr[last_idx]){
            take = arr[i] + solve(i+1, arr, i, dp);
        }
        
        // not take
        int skip = solve(i+1, arr, last_idx, dp);
        
        return dp[i][last_idx+1] = max(take, skip);
    }
    int maxSumIS(vector<int>& arr) {
        // Jai Shri Ram
        n =  arr.size();
        
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, arr, -1, dp);
    }
};