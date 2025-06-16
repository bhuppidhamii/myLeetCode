class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // Jai Shri Ram
        int ans = -1;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (nums[i] < nums[j]) {
                    ans = max(ans, (nums[j] - nums[i]));
                }
            }
        }
        return ans;
    }
};