class Solution {
public:
    void setZeroes(vector<vector<int>>& MAT) {
        int n = MAT.size();
        int m = MAT[0].size();

    vector<bool> row_marked(n, false);
    vector<bool> col_marked(m, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAT[i][j] == 0) {
                row_marked[i] = true;
                col_marked[j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row_marked[i] || col_marked[j]) {
                MAT[i][j] = 0;
            }
        }
    }

    }
};