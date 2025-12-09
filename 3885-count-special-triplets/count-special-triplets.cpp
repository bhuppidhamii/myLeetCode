class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int MOD = 1e9 + 7;

        unordered_map<int, int> suffix;
        for (auto& i : nums) {
            suffix[i]++;
        }

        unordered_map<int, int> prefix;
        int count = 0;
        for (auto& i : nums) {
            // remove from suffix
            if (suffix.find(i) != suffix.end()) {
                suffix[i]--;
                if (suffix[i] == 0) suffix.erase(i);
            }
            long long target = 2 * i;

            // check for double in suffix & mp 2
            long long left = 0, right = 0;
            if (prefix.count(target)) left = prefix[target];
            if (suffix.count(target)) right = suffix[target];

            long long add = (left * right) % MOD;
            count = (count + add) % MOD;
            // add to prefix
            prefix[i]++;
        }
        return count;
    }
};