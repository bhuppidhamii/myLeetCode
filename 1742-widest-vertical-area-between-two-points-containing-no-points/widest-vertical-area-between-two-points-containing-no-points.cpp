class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int ans=INT_MIN;
        for(int i=0; i < points.size()-1; i++){
            int diff = points[i+1][0] - points[i][0];
            ans=max(ans, diff);
        }
        return ans;
    }
};