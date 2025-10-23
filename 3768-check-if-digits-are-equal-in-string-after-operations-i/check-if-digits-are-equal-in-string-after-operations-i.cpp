class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string temp = "";
            int n = s.size();
            for (int i = 1; i < n; i++) {
                int num = s[i - 1] - '0' + s[i] - '0';
                num = num % 10;
                temp += num + '0';
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};