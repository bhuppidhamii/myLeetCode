class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        // Loop through all possible subsets
        for (int mask = 0; mask < (1 << n); mask++) {
            int subsetXOR = 0;
            // For each element in nums, if its corresponding bit in mask is set, include it in the subset
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subsetXOR ^= nums[i];
                }
            }
            sum += subsetXOR;
        }
        return sum;
    }
};
