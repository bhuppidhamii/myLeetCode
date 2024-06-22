class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int oddCount = 0, res = 0;
        for (auto i : nums) {
            oddCount += i % 2;

            if (mp.count(oddCount - k)) {
                res += mp[oddCount - k];
            }

            mp[oddCount]++;
        }
        return res;
    }
};