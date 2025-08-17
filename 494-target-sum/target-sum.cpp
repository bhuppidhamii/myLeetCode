class Solution {
public:
    int solve(int i, vector<int>& nums, int currSum, int target) {
        if (i == nums.size()) {
            if (currSum == target) {
                return 1;
            }
            return 0;
        }

        //  take +num
        int plus = solve(i + 1, nums, currSum + nums[i], target);
        // take -num
        int minus = solve(i + 1, nums, currSum - nums[i], target);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, 0, target);
    }
};