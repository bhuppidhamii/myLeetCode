class Solution {
  public:
    int M=1e9+7;
    int solve(int i, int j, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i >n-1 || j >m-1)
            return 0;
        
        if(i == n-1 && j == m-1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int left = 0;
        if(i+1 < n && grid[i+1][j] != 1){
            left = solve(i+1, j, n, m, grid, dp);
        }
        
        int down = 0;
        if(j+1 < m && grid[i][j+1] != 1){
            down = solve(i, j+1, n, m, grid, dp);
        }
        
        int ways = (left + down) % M;
        return dp[i][j] = ways;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, n, m, grid, dp);
    }
};