class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == true || grid[i][j] == '0') return;

        // mark as visited
        visited[i][j] = true;

        for (auto& d : dirs) {
            int i_ = i + d[0];
            int j_ = j + d[1];
            dfs(i_, j_, grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    dfs(i, j, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};