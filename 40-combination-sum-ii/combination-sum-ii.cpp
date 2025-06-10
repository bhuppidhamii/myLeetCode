class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
        vector<vector<int>>& ans, vector<int>& temp, int currSum) {
        if (currSum > target) {
            return;
        }
        if (currSum == target) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            if( i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
                
            temp.push_back(candidates[i]);

            solve(i+1, candidates, target, ans, temp, currSum + candidates[i]);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, ans, temp, 0);
        return ans;
    }
};