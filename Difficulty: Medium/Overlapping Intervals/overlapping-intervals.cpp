class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Jai Shri Ram
        sort(begin(arr), end(arr));
        
        vector<vector<int>>ans;
        int n = arr.size();
        int i = 0;
        while(i < n){
            int start = arr[i][0];
            int end = arr[i][1];
            int j = i+1;
            while(j<n && arr[j][0]<=end){
                end = max(end, arr[j][1]);
                j++;
            }
            i=j;
            ans.push_back({start, end});
        }
        return ans;
    }
};