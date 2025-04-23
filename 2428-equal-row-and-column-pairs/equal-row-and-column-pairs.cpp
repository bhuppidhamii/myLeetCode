class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;

        // 1. push all rows
        for (auto& v : grid) {
                 mp[v]++;
        }

        // 2. push all columns
        int N = grid.size();
        int count = 0;
        for (int j = 0; j < N; j++) {
            vector<int> col;
            for (int i = 0; i < N; i++) {
                col.push_back(grid[i][j]);
            }
            if (mp.find(col) != mp.end()) {
                count+=mp[col];
            }
        }

        return count;
    }
};