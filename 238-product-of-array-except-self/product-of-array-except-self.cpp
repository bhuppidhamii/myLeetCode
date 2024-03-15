class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                left[i] = nums[i];
            else
                left[i] = left[i - 1] * nums[i];
        }

        vector<int> right(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                right[i] = nums[i];
            else
                right[i] = right[i + 1] * nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans[i] = right[i + 1];
            else if (i == n - 1)
                ans[i] = left[i - 1];
            else
                ans[i] = left[i - 1] * right[i + 1];
        }
        return ans;
    }
};