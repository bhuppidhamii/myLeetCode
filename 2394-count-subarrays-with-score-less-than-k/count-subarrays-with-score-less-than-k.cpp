class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int N = nums.size(), i = 0, j = 0;
        long long score = 1, count = 0;
        while (j < N) {
            sum += nums[j];
            score = (sum * (j - i + 1));

            while (i <= j && score >= k) {
                sum -= nums[i++];
                score = sum * (j - i + 1);
            }

            count += (j - i + 1);
            j++;
        }
        return count;
    }
};