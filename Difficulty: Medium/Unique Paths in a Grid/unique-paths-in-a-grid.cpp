class Solution {
  public:
    int count, n, m;
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>>&dp){
        if(i >= n || j>= m){
            return 0; // robot is out of matrix;
        }
        if(i==n-1 && j==m-1){
            return 1; // robot has reached the bottom-right position
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int left = 0;
        if(j+1 < m && grid[i][j+1] != 1){
            left = solve(i, j+1, grid, dp);
        }
        
        int down = 0;
        if(i+1 < n && grid[i+1][j] != 1){
            down = solve(i+1, j, grid, dp);
        }
        
        return dp[i][j] = left + down; // memoise
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        count=0;
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0,0,grid, dp);
    }
};