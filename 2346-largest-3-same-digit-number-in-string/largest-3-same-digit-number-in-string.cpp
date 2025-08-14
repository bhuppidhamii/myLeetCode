class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 111; i <= 999; i += 111) {
            string str = to_string(i);
            if (num.find(str) != string::npos) {
                ans = str;
            }
        }
        if (ans == "" && (num.find("000") != string::npos)) {
            return "000";
        }
        return ans;
    }
};