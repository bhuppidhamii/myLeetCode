class Solution {
public:
    int N;
    void solve(int i, vector<int>& temp, vector<vector<int>>& ans, vector<int>&nums) {
        if (i >= N) {
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        solve(i+1, temp, ans, nums);

        // not take
        temp.pop_back();
        solve(i+1, temp, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        N = nums.size();
        vector<int> temp;
        solve(0, temp, ans, nums);

        return ans;
    }
};