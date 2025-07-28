class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // Jai Shri Ram
        // row-wise
        int maxRowSum = 0;
        for(auto &arr:mat){
            int sum = accumulate(arr.begin(), arr.end(), 0);
            maxRowSum = max(maxRowSum, sum);
        }

        int opsr=0;
        for(auto &arr:mat){
            int sum = accumulate(arr.begin(), arr.end(), 0);
            int diff = abs(sum-maxRowSum);
            opsr+=diff;
        }
        
        // col-wise
        int maxColSum = 0;
        int N = mat.size();
        for(int i=0; i<N; i++){
            int sum = 0;
            for(int j=0;j<N;j++){
                sum+=mat[j][i];
            }
            maxColSum = max(maxColSum, sum);
        }
        
        int opsc = 0;
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=0; j<N; j++){
                sum+=mat[j][i];
            }
            int diff = abs(maxColSum- sum);
            opsc+=diff;
        }
        
        return max(opsc, opsr);
    }
};