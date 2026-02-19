class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // BF
        unordered_set<int>st;
        for(auto &i:arr){
            st.insert(i);
        }
        vector<int>ans;
        for(int i=low ; i<=high; i++){
            if(st.find(i) ==st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};