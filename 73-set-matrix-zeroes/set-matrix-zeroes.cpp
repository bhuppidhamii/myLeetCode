class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<int> row;
        vector<int> col;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for (auto& rn : row) {
            for (int i = 0; i < c; i++) {
                mat[rn][i] = 0;
            }
        }
        for (auto& cn : col) {
            for (int j = 0; j < r; j++) {
                mat[j][cn] = 0;
            }
        }
    }
};