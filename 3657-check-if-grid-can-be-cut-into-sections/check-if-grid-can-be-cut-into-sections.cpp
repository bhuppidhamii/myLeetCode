class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            int last = ans.back()[1];
            int start = arr[i][0];

            if (start < last) {
                ans.back()[1] = max(last, arr[i][1]);
            } else {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;

        for (auto rec : rectangles) {
            x.push_back({rec[0], rec[2]});
            y.push_back({rec[1], rec[3]});
        }

        vector<vector<int>> x_merged = merge(x);
        vector<vector<int>> y_merged = merge(y);

        if (x_merged.size() >= 3 || y_merged.size() >= 3) {
            return true;
        }
        return false;
    }
};