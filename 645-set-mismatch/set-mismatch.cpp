class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(begin(nums), end(nums));
        map<int, int> mp;
        int twice = 0, missing = 0, n = 1;
        for (auto& i : nums) {
            mp[i]++;

            // twice
            if (mp[i] > 1) {
                twice = i;
            }

            // missing
            if (mp.find(n) == mp.end()) {
                missing = n;
            }
            n++;
        }
        return {twice, missing};
    }
};