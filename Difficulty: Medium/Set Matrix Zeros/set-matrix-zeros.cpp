class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // Jai Shri Ram
        int N=mat.size();
        int M=mat[0].size();
        
        
        bool firstCol=false;
        for(int i=0; i<N; i++){
            if(mat[i][0] == 0){
                firstCol = true;
            }
        }
        
        bool firstRow=false;
        for(int j=0;j<M;j++){
            if(mat[0][j] == 0){
                firstRow=true;
            }
        }
        
        // set markers
        for(int i=1; i<N; i++){
            for(int j=1; j<M; j++){
                if(mat[i][j] == 0){
                    
                    // set row 1st element as 0;
                    mat[i][0] = 0;
                    
                    // set col 1st element as 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<N; i++){
            for(int j=1; j<M; j++){
                
                int row_first_element = mat[i][0];
                int col_first_element = mat[0][j];
                
                if(row_first_element == 0 || col_first_element == 0){
                    mat[i][j] = 0;
                }
            }
        }
        
        if (firstRow) { // if 1st row is impacted
            for (int j = 0; j < M; j++) {
                mat[0][j] = 0;
            }
        }

        if (firstCol) { // if 1st col is impacted
            for (int i = 0; i <N; i++) {
                mat[i][0] = 0;
            }
        }
        
    }
};