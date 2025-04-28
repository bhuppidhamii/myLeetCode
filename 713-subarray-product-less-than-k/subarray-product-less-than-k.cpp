class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        if (k <= 1) {
            return 0;
        }

        int N = nums.size(), i = 0, j = 0;
        int currProd = 1, count = 0;
        while (j < N) {
            currProd *= nums[j];

            while (currProd >= k && i < N) {
                currProd /= nums[i];
                i++;
            }

            int n = (j - i) + 1; // no of subarrays ending at j
            count += n;
            j++;
        }
        return count;
    }
};