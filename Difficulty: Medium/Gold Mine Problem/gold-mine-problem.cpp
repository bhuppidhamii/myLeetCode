class Solution {
  public:
    int N, M;
    vector<vector<int>> dp;

    int collect(int i, int j, vector<vector<int>>& mat) {
        if (i < 0 || i >= N || j >= M)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int rightUp = (i > 0) ? collect(i - 1, j + 1, mat) : 0;
        int right = collect(i, j + 1, mat);
        int rightDown = (i < N - 1) ? collect(i + 1, j + 1, mat) : 0;

        return dp[i][j] = mat[i][j] + max({rightUp, right, rightDown});
    }

    int maxGold(vector<vector<int>>& mat) {
        // Jai Shri Ram
        N = mat.size();
        M = mat[0].size();
        dp.assign(N, vector<int>(M, -1));

        int maxi = 0;
        for (int i = 0; i < N; ++i) {
            maxi = max(maxi, collect(i, 0, mat));
        }
        return maxi;
    }
};