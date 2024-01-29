class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;

        while (i < j) {
            int currSum = nums[i] + nums[j];
            if (currSum == target) {
                return {i + 1, j + 1};
            }
            if (currSum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};