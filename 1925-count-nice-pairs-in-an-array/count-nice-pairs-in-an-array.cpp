class Solution {
public:
    int rev(int n) {
        int ans = 0;
        while (n > 0) {
            int rem = n % 10;
            ans = ans * 10 + rem;
            n /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9 + 7;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }

        map<int, int> m;
        int count = 0;
        for (auto i : nums) {
            count = (count + m[i]) % mod;

            m[i]++;
        }
        return count;
    }
};