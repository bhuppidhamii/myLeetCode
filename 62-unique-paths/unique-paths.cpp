class Solution {
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i >=m || j>=n) return 0;
        
        if(i == m-1 && j == n-1){
            return 1; // we have found 1 path.
        }

        if(dp[i][j] != -1){ // we have al ready visited this path.
            return dp[i][j]; 
        }

        dp[i][j] = solve(i+1, j, m, n, dp) + solve(i, j+1, m, n, dp);
        // memoization
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(0, 0, m, n, dp);
    }
};