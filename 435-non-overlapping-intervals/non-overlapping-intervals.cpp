class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Jai Shri Ram
        sort(intervals.begin(), intervals.end());

        int i = 0, N = intervals.size(), count = 0;
        for (int j = 1; j < N; j++) {
            // overlapping
            if (intervals[j][0] < intervals[i][1]) {
                int ub_i = intervals[i][1];
                int ub_j = intervals[j][1];

                if (ub_j >= ub_i) {
                    // revmove one with greater ub
                    count++;
                } else {
                    i = j;
                    count++;
                }
            } else {
                i = j;
            }
        }
        return count;
    }
};