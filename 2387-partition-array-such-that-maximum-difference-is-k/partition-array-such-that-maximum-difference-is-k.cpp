class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int N = nums.size();
        int i = 0;
        int count = 0;
        while (i < N) {
            int j = i;
            int max_allowed = nums[j] + k;
            while (j < N && nums[j] <= max_allowed) {
                j++;
            }
            count++;
            i++;
            i = j;
        }
        return count;
    }
};