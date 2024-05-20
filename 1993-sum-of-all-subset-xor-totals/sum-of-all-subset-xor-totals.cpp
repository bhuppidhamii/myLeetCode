class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int> temp, vector<vector<int>>& allSubsets) {
        if (i >= nums.size()) {
            allSubsets.push_back(temp);
            return;
        }

        temp.push_back(nums[i]); //take
        solve(nums, i + 1, temp, allSubsets);

        temp.pop_back(); //not-take
        solve(nums, i + 1, temp, allSubsets);
    }
    int subsetXORSum(vector<int>& nums) {
        // make all subsets
        vector<vector<int>> allSubsets;
        vector<int> temp;
        solve(nums, 0, temp, allSubsets);

        int res=0;
        // sum of xor of all subsets
        for(vector<int>&sub:allSubsets){
          int sum=0;
          for(auto num:sub){
            sum^=num;
          }
          res+=sum;
        }
        return res;
    }
};