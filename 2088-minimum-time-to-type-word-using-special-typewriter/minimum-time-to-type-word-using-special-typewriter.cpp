class Solution {
public:
    int minTimeToType(string word) {
        int ans = word.size();
        char st = 'a';
        for(auto x: word) {
            int clk = 26 - abs(x - st);
            int aclk = abs(x - st);
            ans += min(clk, aclk);
            st = x;
        }
        return ans;
    }
};