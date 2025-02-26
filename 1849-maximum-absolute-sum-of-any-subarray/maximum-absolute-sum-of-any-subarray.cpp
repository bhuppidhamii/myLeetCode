class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, currSum = 0;
        // max sum
        for (auto& n : nums) {
            currSum += n;
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }

        // min sum
        currSum = 0;
        int minSum = INT_MAX;
        for (auto& n : nums) {
            currSum += n;
            minSum = min(minSum, currSum);
            if (currSum > 0) {
                currSum = 0;
            }
        }
        return max(maxSum, abs(minSum));
    }
};