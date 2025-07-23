class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x >= y) {
            // remove ab first
            string str = "";
            for (auto& ch : s) {
                if (str.empty()) {
                    str += ch;
                } else {
                    if (str.back() == 'a' && ch == 'b') {
                        str.pop_back();
                        res += x;
                    } else {
                        str += ch;
                    }
                }
            }

            // remove ba
            string str2 = "";
            for (auto& ch : str) {
                if (str2.empty()) {
                    str2 += ch;
                } else {
                    if (str2.back() == 'b' && ch == 'a') {
                        str2.pop_back();
                        res += y;
                    } else {
                        str2 += ch;
                    }
                }
            }
        } else {
            // remove ba
            string str = "";
            for (auto& ch : s) {
                if (str.empty()) {
                    str += ch;
                } else {
                    if (str.back() == 'b' && ch == 'a') {
                        str.pop_back();
                        res += y;
                    } else {
                        str += ch;
                    }
                }
            }

            // remove ab
            string str2 = "";
            for (auto& ch : str) {
                if (str2.empty()) {
                    str2 += ch;
                } else {
                    if (str2.back() == 'a' && ch == 'b') {
                        str2.pop_back();
                        res += x;
                    } else {
                        str2 += ch;
                    }
                }
            }
        }
        return res;
    }
};