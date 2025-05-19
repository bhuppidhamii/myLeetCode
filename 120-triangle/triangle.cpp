class Solution {
public:
    int N;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& triangle, int i, int j) {
        if (i == N - 1) return triangle[i][j];  // Base case: last row

        if (dp[i][j] != -1) return dp[i][j];

        int down = solve(triangle, i + 1, j);
        int diagonal = solve(triangle, i + 1, j + 1);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        N = triangle.size();
        dp = vector<vector<int>>(N, vector<int>(N, -1));
        return solve(triangle, 0, 0);  // Start from top of the triangle
    }
};