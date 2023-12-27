class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            int n = max(nums[i - 1] + 1, nums[i]);
            cnt += (n - nums[i]);
            nums[i] = n;
        }
        return cnt;
    }
};