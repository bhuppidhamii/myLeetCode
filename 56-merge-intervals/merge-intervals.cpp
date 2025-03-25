class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(begin(intervals), end(intervals));
        ans.push_back({intervals[0][0], intervals[0][1]});

        for (int i = 1; i < intervals.size(); i++) {
            int end = ans.back()[1];
            int start = intervals[i][0];

            if (start <= end) {
                ans.back()[1] = max(end, intervals[i][1]);
            } else {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};