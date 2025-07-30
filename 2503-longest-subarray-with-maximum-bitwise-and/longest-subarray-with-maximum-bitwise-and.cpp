class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();

        // find the max_element
        int max_ele = *max_element(nums.begin(), nums.end());

        // find longest subarray having max_value
        int count = 0, max_len = -1;
        for (auto& i : nums) {
            if (i == max_ele) {
                count++;
            } else {
                max_len = max(max_len, count);
                count = 0;
            }
            max_len = max(max_len, count);
        }
        return max_len;
    }
};