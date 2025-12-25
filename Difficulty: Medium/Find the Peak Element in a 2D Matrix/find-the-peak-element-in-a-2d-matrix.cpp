class Solution {
  public:
    int n,m;
    bool check(int i, int j){
        if(i<0||j<0||i>=n||j>=m) return false;
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // Jai Shri Ram
        // BF
        n=mat.size(), m=mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int curr = mat[i][j];
                int top=INT_MIN,bottom=INT_MIN,left=INT_MIN,right=INT_MIN;
                
                if(check(i-1, j)){ // top
                    top = mat[i-1][j];
                }
                if(check(i+1, j)){ // bottom
                    bottom = mat[i+1][j];
                }
                if(check(i, j-1)){ // left
                    left = mat[i][j-1];
                }
                if(check(i, j+1)){ // right
                    right = mat[i][j+1];
                }
                
                if(curr >= top && curr >= bottom && curr >= left && curr >= right){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
