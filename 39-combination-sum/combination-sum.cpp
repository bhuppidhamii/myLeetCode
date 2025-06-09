class Solution {
public:
    void solve(vector<int>& candidates, int target, set<vector<int>>&st, int currSum, vector<int>&temp){
        if(currSum > target){
            return;
        }
        if(currSum == target){
            vector<int>v=temp;
            sort(begin(v), end(v));
            st.insert(v);
            return;
        }
        for(int i=0; i<candidates.size(); i++){
            temp.push_back(candidates[i]);

            solve(candidates, target, st, currSum+candidates[i], temp);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>st;
        vector<int>temp;
        solve(candidates, target, st, 0, temp);
        
        vector<vector<int>>ans;
        for(auto &v:st){
            ans.push_back(v);
        }
        return ans;
    }
};