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
        // 10^9 = 1000000000
        // max no would be - 999999999
        // max sum would be - 81
        vector<int> v(82, 0);

        for (int i = 0; i < nums.size(); i++) {
            int digitSum = sumDigits(nums[i]);

            if (v[digitSum] != 0) { // already present;
                result = max(result, nums[i] + v[digitSum]);
            }

            // if not present - store the max no
            v[digitSum] = max(v[digitSum], nums[i]);
        }
        return result;
    }
};