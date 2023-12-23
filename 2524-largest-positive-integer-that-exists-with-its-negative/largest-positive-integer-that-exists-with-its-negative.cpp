class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            while (l < r && -1 * nums[l] > nums[r] ) {
                l++;
            }
            if (-1*nums[l] == nums[r]) {
                return nums[r];
            }
            r--;
        }
        return -1;
    }
};