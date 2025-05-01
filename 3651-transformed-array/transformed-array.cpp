class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, -1);

        for (int i = 0; i < N; i++) {
            int k = nums[i];
            if (nums[i] > 0) {
                int targetIndex = (i + k) % N;
                res[i] = nums[targetIndex];
            } else if (nums[i] < 0) {
                int targetIndex = (i + k) % N;
                if (targetIndex < 0) targetIndex += N;
                res[i] = nums[targetIndex];
            } else {
                res[i] = nums[i];
            }
        }
        return res;
    }
};