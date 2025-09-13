class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Jai Shri Ram
        
        // sort both x & y in descending order
        sort(begin(x), end(x),[](auto a, auto b){
           return a > b; 
        });
        sort(begin(y), end(y),[](auto a, auto b){
           return a > b; 
        });
        
        int N=x.size(), M=y.size();
        int vs = 1, hs = 1;
        int i = 0, j = 0;
        int totalCost = 0;
        
        while(i < N && j < M){
            int cost = 0;
            if(x[i] >= y[j]){
                cost = x[i]*hs;
                i++, vs++;
            }else{
                cost = y[j]*vs;
                j++, hs++;
            }
            totalCost+=cost;
        }
        
        while(i < N){
            totalCost += x[i]*hs;
            i++, vs++;
        }
        while(j < M){
            totalCost += y[j]*vs;
            j++, hs++;
        }
        return totalCost;
    }
};
