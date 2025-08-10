class Solution {
public:
    bool check(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = check(s, i + 1, j - 1, dp);
        } else {
            return dp[i][j] = false;
        }
    }
    int countSubstrings(string s) {
        int N = s.size(), count = 0;
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (check(s, i, j, dp)) {
                    string str = s.substr(i, j - i + 1);
                    if (str.size() > 0) {
                        count++;
                        // cout<<str<<"\n";
                    }
                }
            }
        }
        return count;
    }
};