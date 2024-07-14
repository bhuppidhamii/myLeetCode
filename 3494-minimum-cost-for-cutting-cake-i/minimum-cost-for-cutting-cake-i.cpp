class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
      sort(begin(horizontalCut),end(horizontalCut),greater<int>());
      sort(begin(verticalCut),end(verticalCut),greater<int>());

        int i=0,j=0;
        int verticalPiece=1;
        int horizontalPiece=1;
        int result=0;
        while(i<m-1&&j<n-1){
          if(horizontalCut[i]>=verticalCut[j]){
            result+=horizontalCut[i]*verticalPiece;
            horizontalPiece++;
            i++;
          }else{
            result+=verticalCut[j]*horizontalPiece;
            verticalPiece++;
            j++;
          }
        }

        while(i<m-1){
          result+=horizontalCut[i]*verticalPiece;
            horizontalPiece++;
            i++;
        }
        while(j<n-1){
          result+=verticalCut[j]*horizontalPiece;
            verticalPiece++;
            j++;
        }
        return result;
    }
};