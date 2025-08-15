class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        // Jai Shri Ram
        intervals.push_back(newInterval);
        
        sort(begin(intervals), end(intervals));
        
        vector<vector<int>>ans;
        
        int N = intervals.size();
        int i=0;
        while(i < N){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            int j = i+1;
            while(j < N && intervals[j][0] <= end){
                end = max(end, intervals[j][1]);
                j++;
            }
            
            ans.push_back({start, end});
            i=j;
        }
        return ans;
    }
};