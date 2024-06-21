class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                for (int j = i - 1; j >= 0; j--) {
                    if (isalpha(s[j])) {
                        s[j] = '$';
                        break;
                    }
                }
            }
        }
        string ans = "";
        for (auto ch : s) {
            if (isalpha(ch)) {
                ans += ch;
            }
        }
        return ans;
    }
};