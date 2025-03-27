class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // 1. find Majority element
        int majority = -1, count = 0;

        int l = nums.size();
        for (int i = 0; i < l; i++) {
            if (count == 0) {
                majority = nums[i];
                count = 1;
            } else if (majority == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        int freq = 0;
        for (auto& n : nums) {
            if (n == majority) {
                freq++;
            }
        }

        count = 0;
        for (int i = 0; i < l; i++) {
            if (nums[i] == majority) {
                count++;
            }

            int rem = freq - count;
            int n1 = i + 1, n2 = l - i - 1;

            if (count > n1 / 2 && rem > n2 / 2) {
                return i;
            }
        }
        return -1;
    }
};