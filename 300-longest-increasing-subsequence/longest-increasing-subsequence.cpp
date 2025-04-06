class Solution {
public:
    int N;
    int solve(int i, int p, vector<int>& nums, vector<vector<int>>& t) {
        if (i >= N) {
            return 0;
        }
        if (p != -1 && (t[i][p] != -1)) {
            return t[i][p];
        }

        // take
        int take = 0;
        if (p == -1 || nums[p] < nums[i]) {
            take = 1 + solve(i + 1, i, nums, t);
        }

        int skip = solve(i + 1, p, nums, t);
        if (p != -1) {
            t[i][p] = max(take, skip);
        }
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        N = nums.size();
        int p = -1;
        vector<vector<int>> t(N + 1, vector<int>(N + 1, -1));

        return solve(0, p, nums, t);
    }
};