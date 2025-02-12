class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {

        int result = -1;
        unordered_map<int, int> mp;

        for (auto& n : nums) {
            int digitSum = sumDigits(n);

            if (mp.count(digitSum)) {
                // already present
                result = max(result, n + mp[digitSum]);
            }

            // if not present - push the max;
            mp[digitSum] = max(n, mp[digitSum]);
        }
        return result;
    }
};