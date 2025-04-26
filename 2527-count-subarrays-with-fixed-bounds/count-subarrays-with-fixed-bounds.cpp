class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minPos = -1, maxPos = -1, culpritIdx = -1;
        long long ans = 0;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (nums[i] == minK) {
                minPos = i;
            }
            if (nums[i] == maxK) {
                maxPos = i;
            }

            if (nums[i] > maxK || nums[i] < minK) {
                culpritIdx = i;
            }

            int smaller = min(minPos, maxPos);
            int temp = smaller - culpritIdx;
            ans += temp > 0 ? temp : 0;
        }
        return ans;
    }
};