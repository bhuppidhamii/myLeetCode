class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        // check if 1st row impacted;
        bool firstCol = false;
        bool firstRow = false;
        for (int i = 0; i < r; i++) {
            if (mat[i][0] == 0) {
                firstCol = true;
            }
        }

        // check if 1st col impacted;
        for (int j = 0; j < c; j++) {
            if (mat[0][j] == 0) {
                firstRow = true;
            }
        }

        // set markers
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (mat[i][j] == 0) {
                    // set 1st row element as 0
                    mat[i][0] = 0;

                    // set 1st col element as 0
                    mat[0][j] = 0;
                }
            }
        }

        // skip 1st row & 1st col for corner case
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {

                // check row 1st element and col 1st element
                int row_first = mat[i][0];
                int col_first = mat[0][j];

                // if any of them is 0, set the mat[i][j] = 0
                if (row_first == 0 || col_first == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        if (firstRow) { // if 1st row is impacted
            for (int j = 0; j < c; j++) {
                mat[0][j] = 0;
            }
        }

        if (firstCol) { // if 1st col is impacted
            for (int i = 0; i < r; i++) {
                mat[i][0] = 0;
            }
        }
    }
};