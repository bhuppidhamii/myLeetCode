class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i + 1 == m + 1) {
                    int flag = 1;
                    int l = i;
                    for (int k = 0; k < m; k++, l++) {
                        if (pattern[k] == 1 && nums[l + 1] > nums[l]) {
                            continue;
                        } else if (pattern[k] == 0 && nums[l + 1] == nums[l]) {
                            continue;
                        } else if (pattern[k] == -1 && nums[l + 1] < nums[l]) {
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
            }
        }
        return ans;
    }
};