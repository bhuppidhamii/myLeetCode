class Solution {
public:
    bool valid(vector<int>& nums, int k, int mid) {
        int parts = 0, N = nums.size();
        int sum = 0, i = 0;
        while (i < N) {
            int j = i;
            while (j < N && nums[j] + sum <= mid) {
                sum += nums[j];
                j++;
            }
            i = j;
            parts++;
            sum = 0;
        }
        return parts <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(begin(nums), end(nums));
        int high = accumulate(begin(nums), end(nums), 0);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (valid(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};