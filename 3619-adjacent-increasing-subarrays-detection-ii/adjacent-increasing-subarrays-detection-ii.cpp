class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        int maxResult = 0;

        for (int i = 1; i < n; i++) {
            if (nums [i] > nums[i-1]) {
                currRun++;
            } else { // increasing order breaks here
                prevRun = currRun;
                currRun = 1;
            }

            maxResult = max(maxResult, currRun/2);
            maxResult = max(maxResult, min(prevRun, currRun));
        }

        return maxResult;
    }
};