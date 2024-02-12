class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            if (i + m >= n) break;
            int flag = 1;
            for (int j = i, k = 0; j + 1 < n, k < m; j++, k++) {
                if (pattern[k] == 1 && nums[j + 1] > nums[j]) {
                    continue;
                } else if (pattern[k] == 0 && nums[j + 1] == nums[j]) {
                    continue;
                } else if (pattern[k] == -1 && nums[j + 1] < nums[j]) {
                    continue;
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                ans++;
            }
        }
        return ans;
    }
};