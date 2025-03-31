class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int currSum = 0;
        int i = 0, j = 0;
        int ans = INT_MAX;

        while (j < n) {
            currSum += nums[j];

            while (currSum >= target) {
                int window = j - i + 1;
                ans = min(ans, window);

                currSum -= nums[i];
                i++;
            }
            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};