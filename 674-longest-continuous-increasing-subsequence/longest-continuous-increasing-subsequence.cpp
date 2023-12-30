class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1, N = nums.size(), i = 0;
        while (i < N) {
            int cnt = 1;
            int j = i + 1;
            while (j < N && nums[j] > nums[j - 1]) {
                j++;
                cnt++;
            }
            ans = max(ans, cnt);
            i = j;
        }
        return ans;
    }
};