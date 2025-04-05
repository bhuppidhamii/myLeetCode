class Solution {
public:
    int N;
    void solve(int i, vector<int>& temp, vector<int>& nums,
               vector<vector<int>>& subsets) {
        if (i >= N) {
            subsets.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        solve(i + 1, temp, nums, subsets);

        // not take
        temp.pop_back();
        solve(i + 1, temp, nums, subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        // genereate all subsets
        vector<int> temp;
        vector<vector<int>> subsets;
        N = nums.size();

        solve(0, temp, nums, subsets);

        int ans = 0;
        for (auto& arr : subsets) {
            int curr_xor = 0;
            for (auto& n : arr) {
                curr_xor ^= n;
            }
            ans += curr_xor;
        }
        return ans;
    }
};