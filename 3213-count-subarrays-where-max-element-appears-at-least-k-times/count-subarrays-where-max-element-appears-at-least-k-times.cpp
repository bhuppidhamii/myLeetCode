class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(begin(nums), end(nums));
        long long ans = 0;
        long long maxCount = 0;
        int N = nums.size(), i = 0, j = 0;

        while (j < N) {
            if (nums[j] == maxi) {
                maxCount++;
            }

            while (maxCount >= k && i < N) {
                ans+=(N-j);
                if (nums[i] == maxi) {
                    maxCount--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};