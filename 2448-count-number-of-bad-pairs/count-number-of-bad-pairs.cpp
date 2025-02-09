class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        long long n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - i;
        }

        map<long, long> mp;
        long long badPairs = 0, totalNumsbeforJ = 0;
        int j = 0;
        while (j < n) {
            totalNumsbeforJ = j;

            badPairs += (totalNumsbeforJ - mp[nums[j]]);

            mp[nums[j]]++;
            j++;
        }
        return badPairs;
    }
};