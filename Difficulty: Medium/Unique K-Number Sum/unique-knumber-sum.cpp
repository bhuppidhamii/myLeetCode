class Solution {
  public:
    void solve(int idx, int target, int k, vector<vector<int>>&ans, vector<int>&temp, set<int>&st){
        if(target < 0 || temp.size() > k) return;
        
        if(target == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx; i<=9; i++){
            if(st.find(i) == st.end()){
                st.insert(i);
                temp.push_back(i);
                
                solve(i+1, target-i, k, ans, temp, st);
                
                temp.pop_back();
                st.erase(i);
            }
        }
    }
    vector<vector<int>> combinationSum(int target, int k) {
        // Jai Shri Ram
        
        vector<vector<int>>ans;
        vector<int>temp;
        set<int>st;
        solve(1, target, k, ans, temp, st);
        
        return ans;
    }
};