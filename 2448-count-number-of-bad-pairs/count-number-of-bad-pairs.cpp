class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - i;
        }

        map<long, long> mp;
        mp[nums[0]]++;
        for (int i = 1; i < n; i++) {
            int totalPairs = i;
            int goodPairs = mp[nums[i]];

            int badPairs = totalPairs - goodPairs;
            ans += badPairs;

            mp[nums[i]]++;
        }
        return ans;
    }
};