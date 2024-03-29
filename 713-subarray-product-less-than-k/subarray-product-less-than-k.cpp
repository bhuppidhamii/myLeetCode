class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        int product = 1;

        while (j < n) {
            product *= nums[j];
            while (product >= k && i < j) {
                product /= nums[i];
                i++;
            }
            if (product < k) {
                count += (j - i + 1);
            }
            j++;
        }
        return count;
    }
};