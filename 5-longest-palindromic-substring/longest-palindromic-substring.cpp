class Solution {
public:
    bool solve(int i, int j, string &s) {
        if (i >= j)
            return true;
        if (s[i] == s[j]) {
            return solve(i + 1, j - 1, s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        int sp = -1, maxLen = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(i, j, s) == true) { // if substr is palindrome
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};