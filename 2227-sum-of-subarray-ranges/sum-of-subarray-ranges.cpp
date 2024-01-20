class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int l = nums.size();
        long long sum = 0;
        for (int i = 0; i < l; i++) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for (int j = i; j < l; j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                sum += (maxi - mini);
            }
        }
        return sum;
    }
};