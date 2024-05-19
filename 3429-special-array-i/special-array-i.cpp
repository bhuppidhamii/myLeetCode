class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;

        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            if ((a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0))
                return false;
        }
        return true;
    }
};