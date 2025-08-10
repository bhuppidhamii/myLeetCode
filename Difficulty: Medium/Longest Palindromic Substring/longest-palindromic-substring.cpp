class Solution {
  public:
    bool check(int i, int j, string &s, vector<vector<int>>&dp){
        if(i >= j) return true;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == s[j]){
            return dp[i][j] = check(i+1, j-1, s, dp);
        }else{
            return dp[i][j] = false;
        }
    }
    string getLongestPal(string &s) {
        // Jai Shri Ram
        int N = s.size();
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        int max_len = 0;
        string ans = "";
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                if(check(i, j, s, dp) == true){
                    int len = j-i+1;
                    if(len > max_len){
                        max_len = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        return ans;
    }
};