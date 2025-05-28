class Solution {
public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1 + 1; r2 < n; r2++) {
                int count = 0;
                for (int c = 0; c < m; c++) {
                    if (mat[r1][c] == 1 && mat[r2][c] == 1) {
                        count++;
                        if (count >= 2) return true; // found a rectangle
                    }
                }
            }
        }
        return false;
    }
};