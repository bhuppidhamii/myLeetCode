class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int M = 1e9 + 7;

        int N = nums.size();
        vector<long long> powers(N, 1);
        for (int i = 1; i < N; i++) {
            powers[i] = (powers[i - 1] * 2) % M;
        }

        int l = 0, r = N - 1;
        long long count = 0;
        while (l <= r) {
            if ((nums[l] + nums[r]) <= target) {
                int diff = (r - l);
                count = (count % M + (powers[diff] % M) % M);
                l++;
            } else {
                r--;
            }
        }
        return count;
    }
};