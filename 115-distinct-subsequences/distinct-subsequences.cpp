class Solution {
public:
    int N,M;
    int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(j == M) return 1;
        if(i == N ) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int take = 0;
        if(s[i] == t[j]){
            take = solve(i+1, j+1, s, t, dp);
        }

        int skip = solve(i+1, j, s, t, dp);
        return dp[i][j] = take + skip;
    }
    int numDistinct(string s, string t) {
        N=s.size();
        M=t.size();
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        return solve(0, 0, s, t, dp);
    }
};