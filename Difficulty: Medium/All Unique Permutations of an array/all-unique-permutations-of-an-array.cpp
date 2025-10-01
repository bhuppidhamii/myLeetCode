class Solution {
  public:
    void solve(vector<int>&arr, set<vector<int>>&rset, vector<int>&temp, set<int>&st){
        if(temp.size() == arr.size()){
            rset.insert(temp);
            return;
        }
        
        for(int i=0; i<arr.size(); i++){
            // if i is not in set
            if(st.find(i) == st.end()){
                temp.push_back(arr[i]);
                st.insert(i);
                
                solve(arr, rset, temp, st);
                
                st.erase(i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // Jai Shri Ram
        sort(begin(arr), end(arr));
        
        set<vector<int>>rset;
        vector<int>temp;
        set<int>st;
        solve(arr, rset, temp, st);
    
        vector<vector<int>>result(rset.begin(), rset.end());
        
        return result;
    }
};