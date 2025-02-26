class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane algorithm
        // -ve mila -> result 0;
        // +ve mila -> result += n;

        int maxSum = INT_MIN, currSum = 0;
        for (auto& n : nums) {
            currSum += n;
            maxSum = max(maxSum, currSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};