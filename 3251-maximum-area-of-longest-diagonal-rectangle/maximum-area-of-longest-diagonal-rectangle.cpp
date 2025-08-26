class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = INT_MIN;
        int ans = 0;
        for(auto &d:dimensions){
            int l = d[0];
            int w = d[1];

            int diag = l*l + w*w;
            // cout<<diag<<" ";
            if(diag > maxDiagonal){
                ans = l*w;
                maxDiagonal = diag;
                // cout<<maxDiagonal;
            }else if(diag == maxDiagonal){
                ans = max(ans, l*w);
            }
        }
        return ans;
    }
};