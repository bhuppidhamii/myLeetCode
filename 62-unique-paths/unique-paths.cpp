class Solution {
public:
    int solve(int i, int j, int& m, int& n, vector<vector<int>>& dp) {
        if (i > m-1 || j > n-1) // robot out of matrix
            return 0;

        if (i == m - 1 && j == n - 1) // robot has reached the target
            return 1;
        
        // cout<<i<<" - "<<j<<"\n";
        if (dp[i][j] != -1)
            return dp[i][j];

        int left = solve(i + 1, j, m, n, dp);

        int down = solve(i, j + 1, m, n, dp);

        return dp[i][j] = left + down; // Memoization
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m, n, dp);
    }
};