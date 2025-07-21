class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count = 0;
        for (auto& ch : s) {
            if (ans.empty()) {
                ans += ch;
                count = 1;
            } else {
                // check if last char is equal
                if (ans.size() > 0 && ans.back() == ch) {
                    if (count < 2) {
                        ans += ch;
                        count++;
                    } else {
                        continue;
                    }
                } else {
                    ans += ch;
                    count = 1;
                }
            }
        }
        return ans;
    }
};