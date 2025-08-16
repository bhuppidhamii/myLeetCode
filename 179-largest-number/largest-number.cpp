class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // convert into to string -> for sorting correctly
        vector<string> v;
        for (auto& i : nums) {
            v.push_back(to_string(i));
        }

        // custom sort
        sort(begin(v), end(v), [](auto& a, auto& b) { 
            return a + b > b + a; 
        });

        string ans = "";
        for (auto& i : v) {
            ans += i;
        }
        // corner case
        if (ans[0] == '0' && ans.back() == '0')
            return "0";
        return ans;
    }
};