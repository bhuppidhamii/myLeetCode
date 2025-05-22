class Solution {
public:
    bool checkDiffArray(int k, vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size(), 0);

        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if (r + 1 < nums.size()) {
                diff[r + 1] -= x;
            }
        }

        int cumSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cumSum += diff[i];
            diff[i] = cumSum;

            if (nums[i] > diff[i]) {
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // check if its already zero array
        auto lambda = [](int x) {
            return x == 0;
        };
        
        if(all_of(begin(nums), end(nums), lambda)) {
            return 0; //no query required because all are already zero
        }

        int N = nums.size();
        int Q = queries.size();
        int low = 0;
        int high = Q - 1;

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (checkDiffArray(mid, nums, queries) == true) {
                ans = mid + 1; // possible ans
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};