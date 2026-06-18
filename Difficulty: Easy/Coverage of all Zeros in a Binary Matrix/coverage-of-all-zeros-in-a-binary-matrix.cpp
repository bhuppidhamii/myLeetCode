class Solution {
  public:
    int calcCoverage(int i, int j,int n, int m, vector<vector<int>>& mat){
        int count = 0;
        // left 
        for(int k=j-1; k>=0; k--){
            if(mat[i][k]==1){
                count+=1;
                break;
            }
        }
        // right
        for(int k=j+1; k<m; k++){
            if(mat[i][k]==1){
                count+=1;
                break;
            }
        }
        // up
        for(int k=i-1; k>=0; k--){
            if(mat[k][j]==1){
                count+=1;
                break;
            }
        }
        // down
        for(int k=i+1; k<n; k++){
            if(mat[k][j]==1){
                count+=1;
                break;
            }
        }
        return count;
    }
    int findCoverage(vector<vector<int>>& mat) {
        // Jai Shri Ram
        int n= mat.size();
        int m = mat[0].size();
        int coverage = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    coverage += calcCoverage(i,j,n,m, mat);
                }
            }
        }
        return coverage;
    }
};
