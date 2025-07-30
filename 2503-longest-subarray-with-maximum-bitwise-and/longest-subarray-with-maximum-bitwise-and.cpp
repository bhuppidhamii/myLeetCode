class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = 0;
        int max_size = 0;
        int streak = 0;
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
                max_size = 0;
                streak = 0;
            }

            if (num == max_val) {
                streak++;
            } else {
                streak = 0;
            }

            max_size = max(max_size, streak);
        }
        return max_size;
    }
};