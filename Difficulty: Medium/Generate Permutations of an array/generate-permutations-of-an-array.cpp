class Solution {
  public:
    int n;
    void solve(vector<int>&arr, vector<vector<int>>&ans, vector<int>&temp, set<int>&st){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){
            if(st.find(arr[i]) == st.end()){ // not present
                temp.push_back(arr[i]);
                st.insert(arr[i]);
                
                solve(arr, ans, temp, st);
                
                st.erase(arr[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // Jai Shri Ram
        n=arr.size();
        
        vector<vector<int>>ans;
        vector<int>temp;
        set<int>st;
        
        solve(arr, ans, temp, st);
        return ans;
    }
};