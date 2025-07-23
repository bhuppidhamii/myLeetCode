class Solution {
public:
    int res;
    string removeAB(string& s, int x) {
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
        return str;
    }
    string removeBA(string& s, int y) {
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
        return str;
    }
    int maximumGain(string s, int x, int y) {
        res = 0;
        if (x >= y) {
            // remove ab first
            string str = removeAB(s, x);

            // remove ba
            string str2 = removeBA(str, y);

        } else {
            // remove ba first
            string str = removeBA(s, y);

            // remove ab
            string str2 = removeAB(str, x);
        }
        return res;
    }
};