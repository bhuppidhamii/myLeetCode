class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int N = nums.size();

        // mini subarray sum - kadane's
        int minSubSum = INT_MAX;
        int curr = 0;
        for (int i = 0; i < N; i++) {
            curr = min(nums[i] + curr, nums[i]);
            minSubSum = min(minSubSum, curr);
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int circularSum = totalSum - minSubSum;


        // max subarray sum - kadane's
        int maxSubSum = INT_MIN;
        curr = 0;
        for (int i = 0; i < N; i++) {
            curr = max(nums[i] + curr, nums[i]);
            maxSubSum = max(maxSubSum, curr);
        }

        // if all elements are -ve
        if(circularSum == 0){ 
            return maxSubSum;
        }
        return max(circularSum, maxSubSum);
    }
};