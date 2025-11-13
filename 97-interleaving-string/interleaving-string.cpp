class Solution {
public:
    int l1, l2, l3;
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<vector<int>>>&dp){
        if(i>=l1 && j>=l2 && k>=l3) return true;

        if(i<l1 && j<l2 && k<l3 && dp[i][j][k] != -1) return dp[i][j][k];

        bool move_i = false;
        if(i<l1 && k<l3 && s1[i]==s3[k]){
            move_i = solve(i+1, j, k+1, s1, s2, s3, dp);
        }

        bool move_j = false;
        if(j<l2 && k<l3 && s2[j]==s3[k]){
            move_j = solve(i, j+1, k+1, s1, s2, s3, dp);
        }

        return dp[i][j][k] = move_i || move_j;
    }
    bool isInterleave(string s1, string s2, string s3) {
        l1=s1.size(), l2=s2.size(), l3=s3.size();
        if(l1+l2 != l3) return false;
        vector<vector<vector<int>>>dp(l1+1, vector<vector<int>>(l2+1, vector<int>(l3+1,-1)));
        return solve(0,0,0,s1,s2,s3, dp);
    }
};