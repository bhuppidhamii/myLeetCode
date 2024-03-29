class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 0;
        int maxEleCount = 0;
        long long count = 0;

        while (j < n) {
            if (nums[j] == maxi) {
                maxEleCount++;
            }
            while (maxEleCount >= k) {
                count += n - j;
                if (nums[i] == maxi) {
                    maxEleCount--;
                }
                i++;
            }
            j++;
        }

        return count;
    }
};