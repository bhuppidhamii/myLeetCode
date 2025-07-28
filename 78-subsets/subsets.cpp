class Solution {
public:
    int N;
    void solve(int i, vector<int>&nums, vector<int>&temp, vector<vector<int>>&all){
        if(i>=N){
            all.push_back(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        solve(i+1, nums, temp, all);
        temp.pop_back();

        // not take
        solve(i+1, nums, temp, all);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        N = nums.size();
        vector<vector<int>>all;
        vector<int>temp;
        solve(0, nums, temp, all);
        return all;
    }
};