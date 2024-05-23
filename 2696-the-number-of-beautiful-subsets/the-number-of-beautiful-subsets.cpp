class Solution {
public:
    int cnt;
    int K;

    void solve(vector<int>& nums, int i, unordered_map<int, int> &temp) {
        if (i >= nums.size()) {
            cnt++;
            return;
        }
        // take
        if (!temp[nums[i] - K] && !temp[nums[i] + K]) {
            temp[nums[i]]++;          // do
            solve(nums, i + 1, temp); // explore
            temp[nums[i]]--;          // undo
        }

        // not-take
        solve(nums, i + 1, temp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        cnt = 0;
        K = k;
        unordered_map<int, int> temp;
        solve(nums, 0, temp);
        return cnt - 1; // remove empty subset
    }
};