class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int N = nums.size();
        int ans = -1;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((nums[i] + nums[j]) == 0) {
                    ans = max(ans, abs(nums[i]));
                }
            }
        }
        return ans;
    }
};