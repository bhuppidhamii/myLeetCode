class Solution {
public:
    bool checkPalindrome(string &s, int i, int j, vector<vector<int>>&dp) {
        if (i >= j)
            return true;
        
        // check in dp first, if it's already calculated
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // memoise in dp -> store the results
        if (s[i] == s[j]) {
            return dp[i][j] = checkPalindrome(s, i + 1, j - 1, dp);
        } else {
            return dp[i][j] = false;
        }
    }
    string longestPalindrome(string s) {
        int N = s.size();
        // cout<<checkPalindrome("aac", 0, 2);
        vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
        string ans = "";
        int max_len = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (checkPalindrome(s, i, j, dp) == true) {
                    int len = j-i+1;
                    if(len > max_len){
                        max_len = len;
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};