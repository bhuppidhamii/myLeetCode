class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // add new interval
        int n=intervals.size();
        if(n==0){
            return {newInterval};
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        //merge the intervals
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(ans.empty()){
                ans.push_back({start, end});
            }else{

                if(intervals[i][0] <= ans.back()[1]){
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }else{
                    ans.push_back({start, end});
                }
            }
        }
        return ans;
    }
};