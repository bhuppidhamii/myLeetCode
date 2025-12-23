class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // Jai Shri Ram
        
        // sort the array
        sort(begin(arr), end(arr));
        vector<int>ans;
        for(auto &q:queries){
            int a = q[0];
            int b = q[1];
            
            auto upper = upper_bound(begin(arr), end(arr), b);
            auto lower = lower_bound(begin(arr), end(arr), a);
            
            int count = upper-lower;
            ans.push_back(count);
        }
        return ans;
    }
};