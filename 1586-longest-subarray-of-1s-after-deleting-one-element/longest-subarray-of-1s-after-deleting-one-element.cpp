class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        int zeroCount = 0;
        int i = 0, maxLen = 0;
        for (int j = 0; j < N; j++) {
            if (nums[j] == 0) {
                zeroCount++;
            }
            
            // shrink window
            while (i < N && zeroCount > 1) {
                if (nums[i] == 0) {
                    zeroCount--;
                }
                i++;
            }

            int len = (j - i + 1) - 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};