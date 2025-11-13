class Solution {
  public:
    int l1, l2, l3;
    bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>>&dp) {
        if (i == s1.size() && j == s2.size()) return true;
        
        if (dp[i][j] != -1) return dp[i][j];
        int k = i + j;
    
        bool take1 = false, take2 = false;
    
        if (i < s1.size() && s1[i] == s3[k])
            take1 = solve(i+1, j, s1, s2, s3, dp);
    
        if (j < s2.size() && s2[j] == s3[k])
            take2 = solve(i, j+1, s1, s2, s3, dp);
    
        return dp[i][j] = take1 || take2;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        // Jai Shri Ram
        l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if(l1+l2 != l3) return false;
        vector<vector<int>>dp(l1+1, vector<int>(l2+1, -1));
        return solve(0,0, s1, s2, s3, dp);
    }
};