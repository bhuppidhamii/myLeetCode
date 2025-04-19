class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));

        int N = nums.size();
        // lower_bound(i) -> return the index of 1st no. which is not less than i;
        // upper_bound(i) -> return the index of 1st no. which is greater than i;
        // it return an iterator -> -begin(nums) to get the actual index.
        long long count = 0;
        for (int i = 0; i < N; i++) {
            auto it = std::lower_bound(nums.begin() + i + 1, nums.end(), (lower - nums[i])) - begin(nums);
            int x = it - i - 1;

            int it2 = std::upper_bound(nums.begin() + i + 1, nums.end(), (upper - nums[i])) - begin(nums);
            int y = it2 - i - 1;

            count += (y - x);
        }
        return count;
    }
};