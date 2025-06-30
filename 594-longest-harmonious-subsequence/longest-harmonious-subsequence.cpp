class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for (auto& i : nums) {
            mp[i]++;
        }
        int longest = 0;
        for (auto& i : mp) {
            int n = i.first;
            if (mp.find(n + 1) != mp.end()) {
                int len = mp[n] + mp[n + 1];
                longest = max(len, longest);
            }
        }
        return longest;
    }
};