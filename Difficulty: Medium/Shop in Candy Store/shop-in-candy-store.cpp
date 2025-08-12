class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Jai Shri Ram
        int N = prices.size();
        sort(prices.begin(), prices.end());
        
        // for min price
        // take i pointer at first and j pinter at last
        // move j pointer k steps for every i
        // if j crosses i -> break
        int minPrice = 0;
        int L = N-1;
        
        for(int i=0; i <= L; i++){
            minPrice += prices[i];
            
            int temp = k;
            while(temp--){
                L--;
            }
        }
        // cout<<minPrice<<"\n";
        
        int maxPrice = 0;
        L=0;
        for(int i=N-1; i>=L; i--){
            maxPrice+=prices[i];
            
            int temp = k;
            while(temp--){
                L++;
            }
        }
        // cout<<maxPrice<<"\n";
        return {minPrice,maxPrice};
    }
};