class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int N = nums.size();
        // a=bq+r
        // a/b=q
        // a%b=r
        for (int i = 0; i < N; i++) {
            // convert into an combined format
            int old_num = nums[i];
            int new_num = nums[nums[i]];

            nums[i] = old_num + N * (new_num % N);
        }

        for (int i = 0; i < N; i++) {
            nums[i] = nums[i] / N;
        }
        return nums;
    }
};