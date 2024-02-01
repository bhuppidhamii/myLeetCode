class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans(n / 3, vector<int>(3, 0));
        int idx = 0;
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            } else {
                int j = i;
                for (int k = 0; k < 3; k++) {
                    ans[idx][k] = nums[j++];
                }
            }
            idx++;
        }
        return ans;
    }
};