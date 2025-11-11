class Solution {
public:
    int n, m;
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j] != -1)return dp[i][j];

        if(s1[i] == s2[j]){
            return 1+solve(i+1, j+1, s1, s2, dp);
        }

        int move_i = solve(i+1, j, s1, s2, dp);
        int move_j = solve(i, j+1, s1, s2, dp);

        return dp[i][j] = max(move_i, move_j);
    }
    int longestCommonSubsequence(string s1, string s2) {
        n = s1.size(), m=s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return solve(0, 0, s1, s2, dp);
    }
};