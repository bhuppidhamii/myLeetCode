class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int N = nums.size();

        // create prefix sum array
        vector<int> prefix(N, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < N; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        vector<int> result(N, 0);
        for (int i = 0; i < N; i++) {

            int leftSum = (i == 0) ? 0 : prefix[i - 1];
            int rightSum = prefix[N - 1] - prefix[i];
            result[i] = ((nums[i] * i) - leftSum) +
                        (rightSum - (nums[i] * (N - i - 1)));
        }
        return result;
    }
};