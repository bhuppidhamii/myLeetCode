class Solution {
public:
    bool check(vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int n : nums) {
            // sum += (n + divisor - 1) / divisor;
            sum += (int)ceil((double)n / divisor);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(begin(nums), end(nums));

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (check(nums, mid, threshold)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};