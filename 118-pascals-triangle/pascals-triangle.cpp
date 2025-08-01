class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int row = 0; row < n; row++) {
            vector<int> temp;
            for (int i = 0; i <= row; i++) {
                if (i == 0 || i == row) {
                    temp.push_back(1);
                } else {
                    int num = ans[row - 1][i] + ans[row - 1][i - 1];
                    temp.push_back(num);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};