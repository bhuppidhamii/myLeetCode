class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1, count = 1, N = nums.size();
        for (int i = 1; i < N; i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
        }
        return max(ans, count);
    }
};