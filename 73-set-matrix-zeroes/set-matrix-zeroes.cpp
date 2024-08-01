class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
              //  row-->0
              for(int row=0;row<n;row++){
                if(matrix[i][row]!=0){
                  matrix[i][row]=-99;
                }
              }

              // col-->0
              for(int col=0;col<m;col++){
                if(matrix[col][j]!=0){
                  matrix[col][j]=-99;
                }
              }
            }
          }
        }

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(matrix[i][j]==-99){
              matrix[i][j]=0;
            }
          }
        }
    }
};