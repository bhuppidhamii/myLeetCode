class Solution {
  public:
    int maxProfit(vector<int> &p) {
        // Jai Shri Ram
        // greedy 
        int n = p.size();
        
        int buy = p[0], profit = 0;
        for(int i=1; i<n; i++){
            if(p[i] > buy){
                profit = max(profit, p[i]-buy);
            }else if(p[i] < buy){
                buy = p[i];
            }
        }
        return profit;
    }
};
