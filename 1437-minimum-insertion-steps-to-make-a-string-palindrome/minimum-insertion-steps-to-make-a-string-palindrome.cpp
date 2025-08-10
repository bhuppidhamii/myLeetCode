class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        // base case
        if (i > j)
            return 0;

        // check if already exists
        if (dp[i][j] != -1)
            return dp[i][j];

        // if i & j are equal------->
        if (s[i] == s[j]) {
            return solve(i + 1, j - 1, s, dp);
        }

        // if i & j are not equal------>
        // 1. move i, add + 1;
        int move_i = 1 + solve(i + 1, j, s, dp);

        // 2. move j, add + 1;
        int move_j = 1 + solve(i, j - 1, s, dp);

        // memoize
        return dp[i][j] = min(move_i, move_j);
    }
    int minInsertions(string s) {
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return solve(0, N - 1, s, dp);
    }
};