class Solution {
  public:
    int n,m;
    int solve(int i, int j, vector<vector<int>>& mat, int k, vector<vector<vector<int>>>& dp){
        if(k<0 || i<0 || i>=n || j<0 || j>=m) return 0;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        if(i == n-1 && j == m-1 && k-mat[i][j] == 0) return 1;
        
        // down
        int down = solve(i+1, j, mat, k-mat[i][j], dp);
        
        // right
        int right = solve(i, j+1, mat, k-mat[i][j], dp);
        
        return dp[i][j][k] = (down + right);
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Jai Shri Ram
        n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        return solve(0, 0, mat, k, dp);
    }
};