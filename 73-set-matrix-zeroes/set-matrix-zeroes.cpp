class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>vp;
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    vp.push_back({i,j});
                }
            }
        }

        for(auto p:vp){
            for(int i=0;i<n;i++){
                matrix[p.first][i]=0;
            }
            for(int j=0;j<m;j++){
                matrix[j][p.second]=0;
            }
        }
    }
};