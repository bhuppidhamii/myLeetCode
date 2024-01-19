class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> t(n, vector<int>(n));

        for (int col = 0; col < n; col++) {
            t[0][col] = matrix[0][col];
        }

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {

                int a = INT_MAX;
                int b = t[row - 1][col];
                int c = INT_MAX;
                
                if (col - 1 >= 0) {
                    a = t[row - 1][col - 1];
                }
                if (col + 1 < n) {
                    c = t[row - 1][col + 1];
                }

                t[row][col] = matrix[row][col] + min({a, b, c});
            }
        }

        // int ans = INT_MAX;
        // int lastRow = n - 1;
        // for (int col = 0; col < n; col++) {
        //     ans = min(ans, t[lastRow][col]);
        // }
        // return ans;
        
        return *min_element(t[n-1].begin(), t[n-1].end());
    }
};