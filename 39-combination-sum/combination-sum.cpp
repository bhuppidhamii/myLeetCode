class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, 
    vector<vector<int>>&ans, int currSum, vector<int>&temp){
        if(currSum > target){
            return;
        }
        if(currSum == target){
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            temp.push_back(candidates[i]);

            solve(i, candidates, target, ans, currSum+candidates[i], temp);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0, candidates, target, ans, 0, temp);
        
        return ans;
    }
};