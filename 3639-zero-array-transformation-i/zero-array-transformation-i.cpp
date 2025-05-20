class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // difference array technique

        // step 1 - create a difference array
        int N = nums.size();
        vector<int> diff(N, 0);
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int x = 1;
            diff[l] += x;
            if (r + 1 < N) {
                diff[r + 1] -= x;
            }
        }

        // step 2 -  cummulative sum
        int cumSum = diff[0];
        for (int i = 1; i < N; i++) {
            cumSum += diff[i];
            diff[i] = cumSum;
        }

        // step 3 - do operation with original array
        for (int i = 0; i < N; i++) {
            if (nums[i] > diff[i]) {
                return false;
            }
        }
        return true;
    }
};