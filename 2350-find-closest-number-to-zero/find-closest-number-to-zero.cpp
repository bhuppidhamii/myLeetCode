class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();

        int min_d = INT_MAX;
        for (int i = 0; i < n; i++) {
            int dist = abs(nums[i]);
            if (dist <= min_d) {
                min_d = dist;
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) == min_d) {
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};