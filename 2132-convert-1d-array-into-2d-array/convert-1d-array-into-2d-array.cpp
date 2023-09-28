class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n< original.size() || m*n > original.size()){
            return {};
        }

        vector<vector<int>> ans(m, vector<int>(n,0));
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[idx++];
                if(idx==original.size()){
                    return ans;
                }
            }
        }
        return ans;
    }
};