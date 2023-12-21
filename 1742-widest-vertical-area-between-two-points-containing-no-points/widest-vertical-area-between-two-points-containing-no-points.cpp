class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        vector<int>x;
        for(auto i:points){
            x.push_back(i[0]);
        }

        int ans=INT_MIN;
        for(int i=0; i<x.size()-1; i++){
            int diff=x[i+1]-x[i];
            ans=max(ans, diff);
        }
        return ans;
    }
};