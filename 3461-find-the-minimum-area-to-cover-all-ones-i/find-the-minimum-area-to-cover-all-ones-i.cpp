class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        int maxCol = INT_MIN, minCol = INT_MAX, minRow = INT_MAX,
            maxRow = INT_MIN;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    maxCol = max(maxCol, j);
                    minCol = min(minCol, j);

                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                }
            }
        }
        int len = maxCol - minCol + 1;
        int width = maxRow - minRow + 1;
        return len * width;
    }
};