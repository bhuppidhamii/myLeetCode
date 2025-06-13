class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int p) {
        int countPairs = 0, N = nums.size();
        int i = 0;
        while (i < N - 1) {
            if (abs(nums[i] - nums[i + 1]) <= mid) {
                countPairs++;
                i += 2;
            } else {
                i += 1;
            }
        }
        return countPairs >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int N = nums.size();
        sort(begin(nums), end(nums));
        int low = 0;
        int high = nums[N - 1] - nums[0];
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};