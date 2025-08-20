class Solution {
public:
    int M, N;
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (i >= M || j >= N || mat[i][j] == 0) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, mat, dp);
        int diag = solve(i + 1, j + 1, mat, dp);
        int down = solve(i + 1, j, mat, dp);

        return dp[i][j] = 1 + min({right, diag, down});
    }
    int countSquares(vector<vector<int>>& mat) {
        M = mat.size();
        N = mat[0].size();
        int ans = 0;
        vector<vector<int>>dp(M+1, vector<int>(N+1, -1));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 1) {
                    int right = solve(i, j + 1, mat, dp);
                    int diag = solve(i + 1, j + 1, mat, dp);
                    int down = solve(i + 1, j, mat, dp);

                    ans += (1 + min({right, diag, down}));
                }
            }
        }
        return ans;
    }
};