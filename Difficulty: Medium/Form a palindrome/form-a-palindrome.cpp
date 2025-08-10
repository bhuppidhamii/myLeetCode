class Solution {
  public:
    int solve(int i, int j, string &s, vector<vector<int>>&dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]){
            return solve(i+1, j-1, s, dp);
        }
        
        int move_i =  1 + solve(i+1, j, s, dp);
        int move_j =  1 + solve(i, j-1, s, dp);
        
        return dp[i][j] = min({move_i, move_j});
    }
    int findMinInsertions(string &s) {
        // Jai Shri Ram
        
        int N = s.size();
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        return solve(0, N-1, s, dp);
    }
};