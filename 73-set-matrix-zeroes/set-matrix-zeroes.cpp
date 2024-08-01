class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //  bruteforce
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> copy(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                copy[i][j] = matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // row----0
                    int r = i;
                    for (int k = 0; k < n; k++) {
                        copy[r][k] = 0;
                    }
                    // col---0
                    int c = j;
                    for (int l = 0; l < m; l++) {
                        copy[l][c] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = copy[i][j];
            }
        }
    }
};