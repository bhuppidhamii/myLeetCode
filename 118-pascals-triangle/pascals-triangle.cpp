class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> arr(i + 1, 1);

            ans.push_back(arr);
        }
        if (n <= 2) {
            return ans;
        }
        for (int row = 2; row < n; row++) {
            for (int col = 1; col < row; col++) {
                ans[row][col] = ans[row - 1][col] + ans[row - 1][col - 1];
            }
        }
        return ans;
    }
};