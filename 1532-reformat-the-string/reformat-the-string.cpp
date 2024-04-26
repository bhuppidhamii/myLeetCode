class Solution {
public:
    string reformat(string s) {
        int cntLetters = 0, cntDigits = 0;
        string l = "", d = "";
        for (auto ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                cntLetters++;
                l += ch;
            } else {
                cntDigits++;
                d += ch;
            }
        }
        int diff = cntLetters - cntDigits;
        if (diff == 1 || diff == 0 || diff == -1) {
            string ans = "";

            if (cntDigits >= cntLetters) {
                while (d.size() > 0 || l.size() > 0) {
                    if (d.size() > 0) {
                        ans += d.back();
                        d.pop_back();
                    }
                    if (l.size() > 0) {
                        ans += l.back();
                        l.pop_back();
                    }
                }
            } else {
                while (d.size() > 0 || l.size() > 0) {
                    if (l.size() > 0) {
                        ans += l.back();
                        l.pop_back();
                    }
                    if (d.size() > 0) {
                        ans += d.back();
                        d.pop_back();
                    }
                }
            }
            return ans;
        }
        return "";
    }
};