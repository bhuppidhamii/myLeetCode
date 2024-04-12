class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k)
            return "0";

        string ans = "";
        for (char &digit : num) {
            while (!ans.empty() && ans.back() > digit && k > 0) {
                ans.pop_back();
                k--;
            }

            if (!ans.empty() || digit != '0') {
                ans.push_back(digit);
            }
        }

        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        if (ans.empty())
            return "0";
        return ans;
    }
};
