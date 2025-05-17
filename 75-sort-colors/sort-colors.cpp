class Solution {
public:
    void sortColors(vector<int>& nums) {
        // counting sort
        vector<int> counts(3, 0);
        for (auto& n : nums) {
            counts[n]++;
        }

        int idx = 0;
        for (int i = 0; i < 3; i++) {
            int freq = counts[i];
            while (freq--) {
                nums[idx++] = i;
            }
        }
    }
};