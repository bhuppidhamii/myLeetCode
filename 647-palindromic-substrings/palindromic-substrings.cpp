class Solution {
public:
    int t[1001][1001];
    bool solve(int i, int j, string& s) {
        if (i >= j)
            return true;

        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (s[i] == s[j]) {
            return t[i][j] = solve(i + 1, j - 1, s);
        }
        return t[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        memset(t, -1, sizeof(t));

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(i, j, s) == true) { // if substr is palindrome
                    cnt++;
                }
            }
        }
        return cnt;
    }
};