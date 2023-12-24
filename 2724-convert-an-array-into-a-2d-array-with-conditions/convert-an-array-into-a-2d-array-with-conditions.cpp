class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int max_rows = 0;
        for (auto i : nums) {
            mp[i]++;
            max_rows = max(max_rows, mp[i]);
        }
        vector<vector<int>> v(max_rows);
        for (auto j : mp) {
            for (int i = 0; i < j.second; i++) {
                v[i].push_back(j.first);
            }
        }

        return v;
    }
};