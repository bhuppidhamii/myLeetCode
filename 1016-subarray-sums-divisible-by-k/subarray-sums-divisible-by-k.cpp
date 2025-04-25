class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        //           rem, freq
        mp[0] = 1; // 0 rem is always present as-> 0 is div by k
        int currSum = 0;
        int count = 0;
        for (auto& n : nums) {
            currSum += n;
            int rem = currSum % k;

            // we dont store - ve rem
            // 7n -4 = 7n-4-7+7
            // if rem is -ve -> (rem + k)
            if (rem < 0) {
                rem += k;
            }
            if (mp.find(rem) != mp.end()) { // if rem is already present
                count += mp[rem];
            }

            mp[rem]++;
        }
        return count;
    }
};