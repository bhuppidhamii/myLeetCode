class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mp[grid[i][j]]++;
            }
        }
        int a, b;
        for (auto& i : mp) {
            if (i.second == 2) {
                a = i.first;
                break;
            }
        }
        int n=grid.size();
        for (int i = 1; i <= n * n; i++) {
            if (mp.find(i) == mp.end()) {
                b = i;
                break;
            }
        }
        return {a, b};
    }
};