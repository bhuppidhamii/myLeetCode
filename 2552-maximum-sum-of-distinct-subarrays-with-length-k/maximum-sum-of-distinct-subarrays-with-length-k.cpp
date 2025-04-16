class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        map<int, int> mp;
        long long sum = 0, currSum = 0;

        for (int i = 0; i < k - 1; i++) {
            mp[nums[i]]++;
            currSum += nums[i];
        }

        for (int i = k - 1; i < N; i++) {
            mp[nums[i]]++;
            currSum += nums[i];

            if (mp.size() == k) {
                sum = max(sum, currSum);
            }

            if (mp[nums[i - k + 1]] == 1) {
                mp.erase(nums[i - k + 1]);
            } else {
                mp[nums[i - k + 1]]--;
            }
            currSum -= nums[i - k + 1];
        }
        return sum;
    }
};