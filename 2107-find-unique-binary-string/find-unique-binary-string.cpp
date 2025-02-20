class Solution {
public:
    string ans = "";
    void solve(string& curr, map<string, int>& mp, int& n) {
        if (!ans.empty())
            return;

        if (curr.size() == n) {
            if (mp.find(curr) == mp.end()) {
                ans = curr;
            }
            return;
        }

        for (char ch = '0'; ch <= '1'; ch++) {
            // do
            curr.push_back(ch);

            // explore
            solve(curr, mp, n);

            // undo
            curr.pop_back();
        }
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string, int> mp;
        for (auto& ch : nums) {
            mp[ch]++;
        }

        string curr = "";
        int n = nums.size();
        solve(curr, mp, n);
        return ans;
    }
};