class Solution {
public:
    int LPS(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i > j) // if i has crossed j
            return 0;

        if (i == j) // if i&j are in the same pos
            return 1;

        // check if already exists
        if (dp[i][j] != -1)
            return dp[i][j];

        int take = 0;
        if (s[i] == s[j]) {
            take = 2 + LPS(i + 1, j - 1, s, dp);
        }

        // move i
        int move_i = LPS(i + 1, j, s, dp);

        // move j
        int move_j = LPS(i, j - 1, s, dp);

        // memoize
        return dp[i][j] = max({take, move_i, move_j});
    }
    int minInsertions(string s) {
        // find x = longest palindromic sub-sequence
        // return n-x;
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        int x = LPS(0, N - 1, s, dp);

        return N - x;
    }
};