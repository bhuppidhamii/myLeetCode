class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cumSum = 0;
        int N = nums.size();
        int count = 0;
        for (int i = 0; i < N; i++) {
            cumSum += nums[i];

            if (mp.find(cumSum - k) != mp.end()) {
                count += mp[cumSum - k];
            }
            mp[cumSum]++;
        }
        return count;
    }
};