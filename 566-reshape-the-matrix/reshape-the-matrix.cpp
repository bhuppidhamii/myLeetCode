class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() == r && mat[0].size() == c) {
            return mat;
        }

        vector<int> v;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                v.push_back(mat[i][j]);
            }
        }

        if (v.size() != r * c) {
            // If the reshape is not possible, return the original matrix.
            return mat;
        }

        int idx = 0;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = v[idx++];
            }
        }
        return ans;
    }
};
