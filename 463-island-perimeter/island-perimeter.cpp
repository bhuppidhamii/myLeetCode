class Solution {
public:
    int m, n;
    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return false;
        }
        return true;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    continue;
                } else {
                    // top
                    perimeter += isSafe(i, j - 1, grid) == 1 ? 0 : 1;

                    // left
                    perimeter += isSafe(i - 1, j, grid) == 1 ? 0 : 1;

                    // bottom
                    perimeter += isSafe(i + 1, j, grid) == 1 ? 0 : 1;

                    // right
                    perimeter += isSafe(i, j + 1, grid) == 1 ? 0 : 1;

                    grid[i][j] = -1;
                }
            }
        }
        return perimeter;
    }
};