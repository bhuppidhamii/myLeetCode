class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j] != nums[j + 1]) {
                j++;
            }
            int len = j - i + 1;
            ans += (long long)len * (len + 1) / 2;
            i = j + 1;
        }
        return ans;
    }
};