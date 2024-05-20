class Solution {
public:
    int totalXOR;
    void solve(vector<int>& nums, int i, int currXOR) {
        if (i >= nums.size()) {
            totalXOR += currXOR;
            return;
        }

        solve(nums, i + 1, currXOR ^ nums[i]);

        solve(nums, i + 1, currXOR);
    }
    int subsetXORSum(vector<int>& nums) {
        totalXOR = 0;
        solve(nums, 0, 0);
        return totalXOR;
    }
};