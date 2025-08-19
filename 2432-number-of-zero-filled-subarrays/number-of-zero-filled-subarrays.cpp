class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, ans = 0;
        int l = nums.size();

        for (int i = 0; i < l; i++) {
            if (nums[i] == 0) {
                count++;
                ans += count;
            } else {
                count = 0;
            }
        }
        return ans;
    }
};