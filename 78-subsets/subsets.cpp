class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int i, vector<int>& temp) {
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        solve(nums, i + 1, temp); // explore

        // not take
        temp.pop_back();
        solve(nums, i + 1, temp); // explore
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums, 0, temp);

        return ans;
    }
};